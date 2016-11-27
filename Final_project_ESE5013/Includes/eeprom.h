/*
 * eeprom.h
 *
 *  Created on: 27-Nov-2016
 *      Author: Admin
 */

#ifndef INCLUDES_EEPROM_H_
#define INCLUDES_EEPROM_H_

void EEPROMwrite(uint16_t address, uint8_t data);
uint8_t EEPROMread(uint16_t address);
void eereset(void);
void EEPROM_pag_write(uint16_t address, uint8_t *data,uint32_t no_of_bytes);
void EEPROM_Ack_polling(void);



#endif /* INCLUDES_EEPROM_H_ */
