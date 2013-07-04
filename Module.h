/*
	Module.h - Library for defining a module and sending/receiving its id and value over I2C.
 */

#ifndef Module_h
#define Module_h

#include "Arduino.h"

class Module
{
	public:
		Module(char* id, int value);
		void setValue(int value);
		int getValue();
		int parseValue(char string[]);
		char* getID();
		void slaveSendData();
		char* getData(char buf[]);
	private:
		int _value;
		char * _id;
};

#endif