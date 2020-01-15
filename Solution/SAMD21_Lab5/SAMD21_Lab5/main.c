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
	
	printf("SAMD21_Lab5\n");
	
	uint8_t spi_tx[5] = {0x00};
	uint8_t spi_rx[5] = {0x00};
	struct spi_xfer spi_packet;
	
	spi_m_sync_enable(&SPI_0);
	
	gpio_set_pin_level(CS_PIN, false);
	
	//TX packet
	spi_packet.txbuf = spi_tx;
	spi_packet.rxbuf = 0;
	spi_packet.size = 1;
	spi_tx[0] = 0x9F;
	spi_m_sync_transfer(&SPI_0, &spi_packet);
	
	//RX packet
	spi_packet.txbuf = 0;
	spi_packet.rxbuf = spi_rx;
	spi_packet.size = 4;
	spi_m_sync_transfer(&SPI_0, &spi_packet);
	
	gpio_set_pin_level(CS_PIN, true);
	
	hex_dump(spi_rx, 5);	
	
	/* Replace with your application code */
	while (1) {
	}
}
