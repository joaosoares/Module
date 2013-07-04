/**
 * AUTOHOME MODULE LIBRARY
 * Arduino Library to control the LED Module device.
 *
 * July 2013.
 */

#ifndef Module_h
#define Module_h

#include <Arduino.h>

class Module
{
  public:
  	void actOn(uint8_t []);
  	bool statusRequested();
  	uint8_t* getStatus();
  private:
  	uint8_t setBrightness(uint8_t);
}