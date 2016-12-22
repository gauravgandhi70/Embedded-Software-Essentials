/*
 * led.h
 *
 *  Created on: 07-Oct-2016
 *      Author: Admin
 */

#ifndef INCLUDES_LED_H_
#define INCLUDES_LED_H_

typedef enum
{
	OFF,
	RED,
	YELLOW,
	GREEN,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE
}LEDColour_t;



void LED_Init();
void LED_Control(uint8_t Character);
void LEDFunction(LEDColour_t LEDColour, uint16_t Brightness);

#endif /* INCLUDES_LED_H_ */
