#include <atmel_start.h>

struct io_descriptor *io;

static void button_pressed_interrupt_handler(void)
{
	gpio_toggle_pin_level(LED0);
	io_write(io, (uint8_t *)"button pressed!\n", 16);
}


int main(void)
{
	
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	ext_irq_register(PA15, button_pressed_interrupt_handler);
	
	printf("hello world\n");
	
	usart_sync_get_io_descriptor(&USART_0, &io);
	usart_sync_enable(&USART_0);

	/* Replace with your application code */
	while (1) {
		
#if 0 //Blinky LED Lab 
		gpio_toggle_pin_level(LED0);
		delay_ms(1000);
#endif

#if 0 // Polling Button Lab
		if(gpio_get_pin_level(SW0) == false){
			// Button pressed, turn LED on
			gpio_set_pin_level(LED0, false);
		}
		else{
			// vice versa
			gpio_set_pin_level(LED0, true);
		}
#endif

	}
}