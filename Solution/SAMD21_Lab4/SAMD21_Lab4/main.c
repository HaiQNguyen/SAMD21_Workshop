#include <atmel_start.h>

void hex_dump(uint8_t * buff, uint32_t size)
{	
	uint16_t i = 0;
	uint8_t line_count = 0;
	for(;i < size; i++) {
		printf("0x%02x, ",buff[i]);
		line_count++;
		if(line_count == 8) {
			printf("\r\n");
			line_count = 0;
		}
	}
	printf("\r\n");
	
	
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	printf("SAMD21_Lab4\n");
	
	uint8_t i2c_data[4] = {0};
	
	i2c_m_sync_enable(&I2C_0);
	i2c_m_sync_set_slaveaddr(&I2C_0, 0x60, I2C_M_SEVEN);

	// send the wake by writing to an address of 0x00
	struct _i2c_m_msg packet = {
		.addr   = 0x00,
		.len    = 0,
		.buffer = NULL,
		.flags  = I2C_M_SEVEN | I2C_M_STOP,
	};
	
	// Send the 00 address as the wake pulse; part will NACK, so don't check for status
	i2c_m_sync_transfer(&I2C_0, &packet);
	
	delay_us(800);
	
	// receive the wake up response
	packet.addr = 0x60;
	packet.len = 4;
	packet.buffer = i2c_data;
	packet.flags  = I2C_M_SEVEN | I2C_M_RD | I2C_M_STOP;
	
	i2c_m_sync_transfer(&I2C_0, &packet);

	hex_dump(i2c_data, 4);
	
	/* Replace with your application code */
	while (1) {
	}
}
