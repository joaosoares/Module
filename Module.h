/**
 * AUTOHOME MODULE LIBRARY
 * Arduino Library to control the LED Module device.
 *
 * July 2013.
 */

#ifndef Module_h
#define Module_h

// Commands for parsing body of packet
#define CMD_SET_BRIGHTNESS 30
#define CMD_LED_OFF 31
#define CMD_STATUS_REQ 32

/* Defines used for shifting into status flag byte */
#define FLAG_STATUS_REQ 0

// LED PIN DECLARATION
#define PIN_LED 9

#include <Arduino.h>

class Module
{
  public:
  	Module();
  	void actOn(uint8_t []);
  	bool statusRequested();
  	void getStatus(uint8_t []);
  private:
  	uint8_t setBrightness(uint8_t);
  	uint8_t brightness;
  	uint8_t status;
};

#endif
