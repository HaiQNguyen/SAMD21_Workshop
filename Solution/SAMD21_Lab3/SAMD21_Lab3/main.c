#include <atmel_start.h>

bool conversion_complete = false;
uint8_t adc_buffer = 0;
uint16_t dac_buffer = 0;

void ADC_ConversionComplete(const struct adc_async_descriptor *const descr, const uint8_t channel)
{
	conversion_complete = true;
}

int main(void)
{	
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	printf("SAMD21_Lab3\n");
	
	adc_async_register_callback(&ADC_0, 0, ADC_ASYNC_CONVERT_CB, ADC_ConversionComplete);
	adc_async_enable_channel(&ADC_0, 0);
	adc_async_start_conversion(&ADC_0);
	
	dac_async_enable_channel(&DAC_0, 0);
	dac_async_write(&DAC_0, 0, &dac_buffer, 1);

	while (1) {
		if(conversion_complete == true){
			adc_async_read_channel(&ADC_0,0,&adc_buffer,1);
			conversion_complete = false;
		}
		dac_buffer = (uint16_t)((1023 * adc_buffer)/255);
		printf("adc: %d\n",adc_buffer);
		dac_async_write(&DAC_0, 0, &dac_buffer, 1);
		delay_ms(100);
		adc_async_start_conversion(&ADC_0);
	}
}
