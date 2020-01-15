#include <atmel_start.h>

uint32_t duty_cycle = 0;
bool fade_in = true;
uint32_t timer_count = 0;
struct timer_task TIMER_0_task1;


static void TIMER_0_task1_cb(const struct timer_task *const timer_task)
{
	timer_count++;
	printf("timer count: %d\n", timer_count);
}

static void PWM0_Period_callback(const struct pwm_descriptor *const descr)
{
	if(fade_in){
		duty_cycle = duty_cycle + 10;
		if(duty_cycle == 1000){
			fade_in = false;
		}	
	}
	else{
		duty_cycle = duty_cycle - 10;
		if(duty_cycle == 0){
			fade_in = true;
		}
	}
	
	pwm_set_parameters(&PWM_0, 1000, duty_cycle);
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	printf("SAMD21_Lab2\r\n");
	
	pwm_register_callback(&PWM_0, PWM_PERIOD_CB, PWM0_Period_callback);
	pwm_set_parameters(&PWM_0, 1000, duty_cycle);
	pwm_enable(&PWM_0);
	
	TIMER_0_task1.interval = 1000;
	TIMER_0_task1.cb       = TIMER_0_task1_cb;
	TIMER_0_task1.mode     = TIMER_TASK_REPEAT;
	
	timer_add_task(&TIMER_0, &TIMER_0_task1);
	timer_start(&TIMER_0);
	
	/* Replace with your application code */
	while (1) {
	}
}
