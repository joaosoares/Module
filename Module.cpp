/**
 * AUTOHOME MODULE LIBRARY
 *
 * July 2013
 */

#include "Arduino.h"
#include "Module.h"

Module::Module()
{
  // Start LED brightness at zero
  brightness = 0;
  // Global status set to 0x00 at initialization
  status = 0x00;

}

// Parses the body of the packet and evaluates commands
void Module::actOn(uint8_t data[])
{
  while (i < sizeof(data[]))
  {
    switch(data[i])
    {
      // Set brightness of LED by changing value of variable
      case(CMD_SET_BRIGHTNESS):
        brightness = data[i++];
        break
      // Turn LED off
      case(CMD_LED_OFF):
        brightness = 0;
        break
      // Request status update by updating global status 
      case(CMD_STATUS_REQ):
        status |= (1<<FLAG_STATUS_REQ);
        break
      // CONTINUE WITH LIST OF POSSIBLE COMMANDS AND ACTIONS!!!
    }

    // Increment i
    i++;
  }
}

bool Module::statusRequested()
{
  // Check status bit corresponding to a status request
  // Requires masking of status to eliminate other bits
  if (status & (1<<FLAG_STATUS_REQ))
  {
    // Clear flag and return true
    status &= ~(1<<FLAG_STATUS_REQ);
    return true
  }

  // If status was not requested 
  return false
}

uint8_t* Module::getStatus()
{
  
}

uint8_t setBrightness(uint8_t value)
{
  analogWrite(PIN_LED,brightness);
}