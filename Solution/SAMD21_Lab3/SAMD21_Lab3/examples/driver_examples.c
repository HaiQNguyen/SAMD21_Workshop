/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

static void convert_cb_ADC_0(const struct adc_async_descriptor *const descr, const uint8_t channel)
{
}

/**
 * Example of using ADC_0 to generate waveform.
 */
void ADC_0_example(void)
{
	adc_async_register_callback(&ADC_0, 0, ADC_ASYNC_CONVERT_CB, convert_cb_ADC_0);
	adc_async_enable_channel(&ADC_0, 0);
	adc_async_start_conversion(&ADC_0);
}

/**
 * Example of using TARGET_IO to write "Hello World" using the IO abstraction.
 */
void TARGET_IO_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&TARGET_IO, &io);
	usart_sync_enable(&TARGET_IO);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

static uint16_t example_DAC_0[10] = {0, 100, 200, 300, 400, 500, 600, 700, 800, 900};

static void tx_cb_DAC_0(struct dac_async_descriptor *const descr, const uint8_t ch)
{
	dac_async_write(descr, 0, example_DAC_0, 10);
}

/**
 * Example of using DAC_0 to generate waveform.
 */
void DAC_0_example(void)
{
	dac_async_enable_channel(&DAC_0, 0);
	dac_async_register_callback(&DAC_0, DAC_ASYNC_CONVERSION_DONE_CB, tx_cb_DAC_0);
	dac_async_write(&DAC_0, 0, example_DAC_0, 10);
}
