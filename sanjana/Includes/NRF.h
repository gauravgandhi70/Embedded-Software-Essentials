/*
 * nrf.h
 *
 * 
 */

#ifndef SOURCES_NRF_H_
#define SOURCES_NRF_H_

#define NORDIC_CONFIG_REG (0x00)
#define NORDIC_TXADDR_REG (0x10)
#define NORDIC_POWER_UP (0x01)
#define NORDIC_POWER_UP_MASK (0x02)
#define NORDIC_POWER_DOWN_MASK (0x00)
#define NORDIC_EN_AA_REG (0x01)
#define NORDIC_EN_RXADDR_REG (0x02)
#define NORDIC_SETUP_AW_REG (0x03)
#define NORDIC_SETUP_RETR_REG (0x04)
#define NORDIC_RF_CH_REG (0x05)
#define NORDIC_RF_SETUP_REG (0x06)
#define NORDIC_STATUS_REG (0x07)
#define RX_ADDR_P0_REG (0x0A)
#define TX_ADDR (0x10)
#define FIFO_STATUS_REG (0x17)

void nrf_read_data();
void nrf_transmit_data();
void nrf_flush_rx_fifo();
void nrf_flush_tx_fifo();
void nrf_read_register(unsigned char address);
void nrf_write_register(unsigned char address);
void nrf_config_write();
void nrf_config_read();
void nrf_status_read();
void nrf_rfsetup_transmit();
void nrf_rfsetup_receive();
void nrf_fifostatus_read();
void nrf_tx_addr_read();
void nrf_tx_addr_write();
void nrf_rx_addr_read();
void nrf_rx_addr_write();



#endif /* SOURCES_NRF_H_ */
