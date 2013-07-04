#include "Arduino.h"
#include "Module.h"
#include "Wire.h"


Module::Module(char id[], int value)
{
	_id = id;
	_value = value;
}

/**
 * Sets the value parameter for this module
 * Eg. to change the brightness of the lamp controlled by it
 * @param value the value from 0-999 that will be the new one
 */
void Module::setValue(int value)
{
	_value = value;
}

/**
 * Returns the current value parameter
 * @return The value parameter
 */
int Module::getValue()
{
	return _value;
}

/**
 * [Module::getID description]
 * @return [description]
 */
char* Module::getID()
{
  return _id;
}

char* Module::getData(char buf[])
{
  for (int i = 0; i < 3; i++)
  {
    buf[i] = _id[i];
  }
  char itoa_buffer[4];
  itoa(getValue(), itoa_buffer, 10);
  for(int i = 3; i< 6; i++)
  {
    buf[i]=itoa_buffer[i-3];
  }
  return buf;
}

/**
 * Function to get the integer value of a Module string
 * @param  string The string, usually received via I2C
 * @return        retunrs the integer value between 0-999 represented by the value section of the string (last 3 digits)
 */
int Module::parseValue(char string[])
{
  char value_section[4];
  for (int i = 0; i<3; i++)
  {
    value_section[i] = string[i+3];
  }
  return atoi(value_section);
}

void Module::slaveSendData()
{
  char buffer[7];
  Wire.write(getData(buffer));
}

