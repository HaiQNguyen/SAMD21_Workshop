/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

struct usart_sync_descriptor TARGET_IO;

struct pwm_descriptor PWM_0;

void TARGET_IO_PORT_init(void)
{

	gpio_set_pin_function(PA22, PINMUX_PA22C_SERCOM3_PAD0);

	gpio_set_pin_function(PA23, PINMUX_PA23C_SERCOM3_PAD1);
}

void TARGET_IO_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM3);
	_gclk_enable_channel(SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC);
}

void TARGET_IO_init(void)
{
	TARGET_IO_CLOCK_init();
	usart_sync_init(&TARGET_IO, SERCOM3, (void *)NULL);
	TARGET_IO_PORT_init();
}

void PWM_0_PORT_init(void)
{

	gpio_set_pin_function(PB00, PINMUX_PB00E_TC7_WO0);

	gpio_set_pin_function(PB01, PINMUX_PB01E_TC7_WO1);
}

void PWM_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC7);
	_gclk_enable_channel(TC7_GCLK_ID, CONF_GCLK_TC7_SRC);
}

void PWM_0_init(void)
{
	PWM_0_CLOCK_init();
	PWM_0_PORT_init();
	pwm_init(&PWM_0, TC7, _tc_get_pwm());
}

void system_init(void)
{
	init_mcu();

	TARGET_IO_init();

	PWM_0_init();
}
