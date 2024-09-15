/*
  Based off of WiiChuck library - https://github.com/coopermaa/Wiichuck
 */

#ifndef _ArduboyWiiChuck_h_
#define _ArduboyWiiChuck_h_

#include <inttypes.h>
#include <Wire.h>

// Calibration joystick values
#define NUNCHUK_JOYSTICK_X_ZERO 128
#define NUNCHUK_JOYSTICK_Y_ZERO 128

class ArduboyWiiChuck {
  private:
    static const int address = 0x52;
    unsigned char i2cBuffer[6];
		
  public:
    void init();
		   
    // Requests data from the nunchuck
    uint8_t poll();
        
    inline int joyX() { return (int)i2cBuffer[0] - NUNCHUK_JOYSTICK_X_ZERO; }    
    inline int joyY() { return (int)i2cBuffer[1] - NUNCHUK_JOYSTICK_Y_ZERO; }

    inline uint8_t buttonZ() { return ((i2cBuffer[5] >> 0) & 1) ? 0 : 1; }
    inline uint8_t buttonC() { return ((i2cBuffer[5] >> 1) & 1) ? 0 : 1; }
};

#endif