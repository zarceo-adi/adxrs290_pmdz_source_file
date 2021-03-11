/*****************************************************************************
 * adxrs290_prod_test.c
 *****************************************************************************/

#include <sys/platform.h>
#include "adi_initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "platform_init.h"
#include "spi.h"
#include "spi_extra.h"
#include "error.h"
#include "irq.h"
#include "irq_extra.h"
#include "uart.h"
#include "uart_extra.h"
#include "timer.h"
#include "adxrs290.h"
#include "gpio.h"
#include "delay.h"
#define UART_DEVICE_ID	0
#define INTC_DEVICE_ID	0
#define UART_IRQ_ID		ADUCM_UART_INT_ID
#define UART_BAUDRATE	115200

static volatile uint8_t read_now = 0;

void sync_gpio_callback(void *app_param, uint32_t event,
		       void *data)
{
		read_now = 1;
}

int main(int argc, char *argv[])
{
	/**
	 * Initialize managed drivers and/or services that have been added to 
	 * the project.
	 * @return zero on success 
	 */
	adi_initComponents();

	struct uart_init_param uart_init_par;
	struct uart_desc *uart_device;

	struct aducm_uart_init_param platform_uart_init_par = {
			.parity = UART_NO_PARITY,
			.stop_bits = UART_ONE_STOPBIT,
			.word_length = UART_WORDLEN_8BITS
		};

	int32_t ret;
	int16_t rateX;
	int16_t rateY;
	//double rateX;
	//double rateY;
	int16_t temp;

	uint8_t uart_data[100];
	pwr_setup();

	/* SYNC pin */
	struct gpio_desc *sync_gpio;
	struct gpio_init_param sync_gpio_param = {
			.number = 0x10,
			.extra = NULL
	};

	/* LED indicators GPIO */
	struct gpio_desc *led1_gpio;
	struct gpio_desc *led2_gpio;
	struct gpio_init_param led1_gpio_param = {
			.number = 0x20,
			.extra = NULL
	};
	struct gpio_init_param led2_gpio_param = {
			.number = 0x1F,
			.extra = NULL
	};

	gpio_get(&sync_gpio, &sync_gpio_param);
	gpio_get(&led1_gpio, &led1_gpio_param);
	gpio_get(&led2_gpio, &led2_gpio_param);

	gpio_direction_input(sync_gpio);
	// Start with all LEDs off
	gpio_direction_output(led1_gpio, GPIO_LOW);
	gpio_direction_output(led2_gpio, GPIO_LOW);

	/* IRQ initial configuration. */
	struct irq_init_param irq_init_param;

	/* IRQ instance. */
	struct irq_ctrl_desc *irq_desc;
	int32_t platform_irq_init_par = 0;
	struct gpio_irq_config gpio_irq;

	/* callback for the sync pin */
	struct callback_desc sync_cb;
	irq_init_param = (struct irq_init_param ) {
			.irq_ctrl_id = INTC_DEVICE_ID,
			.extra = &platform_irq_init_par
		};


	ret = irq_ctrl_init(&irq_desc, &irq_init_param);
	if(ret < 0)
		return ret;
	gpio_irq.gpio_handler = sync_gpio;
	gpio_irq.mode = GPIO_GROUP_POSITIVE_EDGE;
	sync_cb.callback = sync_gpio_callback;
	sync_cb.config = &gpio_irq;
	sync_cb.ctx = NULL;

	ret = irq_register_callback(irq_desc, ADUCM_GPIO_A_INT_ID,
					    &sync_cb);

	ret = irq_global_enable(irq_desc);
	if (ret < 0)
		return ret;
	ret = irq_enable(irq_desc, ADUCM_GPIO_A_INT_ID);
	if (ret < 0)
		return ret;

	uart_init_par = (struct uart_init_param) {
			.device_id = UART_DEVICE_ID,
			.baud_rate = UART_BAUDRATE,
			.extra = &platform_uart_init_par
		};

	//uart_init(&uart_device, &uart_init_par);

	ret = (uart_init(&uart_device, &uart_init_par));
	if ( ret != SUCCESS)
			return 0;

	struct aducm_spi_init_param aducm_param = {
			.continuous_mode = true,
			.dma = false,
			.half_duplex = false,
			.master_mode = MASTER,
			.spi_channel = SPI1
	};

	struct spi_init_param init_param = {
			.chip_select = 0,
			.extra = &aducm_param,
			.max_speed_hz = 900000,
			.mode = SPI_MODE_3,
			.platform_ops = NULL
	};

	struct adxrs290_init_param adxrs290_param = {
			.spi_init = init_param,
			.mode = ADXRS290_MODE_MEASUREMENT,
			.lpf = ADXRS290_LPF_480HZ,
			.hpf = ADXRS290_HPF_ALL_PASS
	};

	struct adxrs290_dev *adxrs290_device;

	// TEST 1: This will test if SPI is working
	ret = adxrs290_init(&adxrs290_device, &adxrs290_param);
	if (ret < 0)
		return ret;
	mdelay(1000);
	gpio_set_value(led1_gpio, GPIO_HIGH);
	gpio_set_value(led2_gpio, GPIO_HIGH);

	// TEST 2: This will test if SPI write to register is working (optional)
	// Write LPF and HPF then read. Should be able to read was was written

	// TEST 3: This will test if interrupt is working

	// If Test 1-3 passes: LED is steady.
	// Start Test 4:
	// rotate X axis CCW or CW, LED should blink while moving.
	// rotate Y axis CCW or CW, LED should blink while moving.
	read_now=1;
	while(true)
	{
		if (read_now)
		{
			read_now=0;
			adxrs290_get_rate_data_all(adxrs290_device,
					&rateX, &rateY, &temp);

			sprintf((char *)uart_data, "X: %d Y: %d\r\n", rateX, rateY);
			uart_write(uart_device, uart_data, strlen((char *)uart_data));

			//uart_write(uart_device, uart_data, strlen((char *)uart_data));
			//uart_write(uart_device, &uart_data[0], strlen(uart_data));
			//uart_write(uart_device, (uint8_t *)uart_data, strlen(uart_data));

			if(rateX>5000 || rateX < -5000){
				//LED1 OFF
				gpio_set_value(led1_gpio, GPIO_LOW);
			}
			else{
				//LED1 ON
				gpio_set_value(led1_gpio, GPIO_HIGH);
			}
			if(rateY>5000 || rateY < -5000){
				//LED2 OFF
				gpio_set_value(led2_gpio, GPIO_LOW);
			}
			else{
				//LED2 ON
				gpio_set_value(led2_gpio, GPIO_HIGH);
			}
			mdelay(500);
		}
	}

	return 0;
}

