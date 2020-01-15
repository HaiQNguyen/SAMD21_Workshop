#include <atmel_start.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	printf("Hello world\r\n");
	
	pwm_set_parameters(&PWM_0, 10000, 2000);
	pwm_enable(&PWM_0);
	
	/* Replace with your application code */
	while (1) {
	}
}
