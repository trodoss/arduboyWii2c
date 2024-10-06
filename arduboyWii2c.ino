#include <Arduboy2.h>
#include <Wire.h>
#include "ArduboyWiiChuck.h"

/*
ArduboyWiiChuck class - Based off of WiiChuck library - https://github.com/coopermaa/Wiichuck
*/

Arduboy2 arduboy;
ArduboyWiiChuck wii;

void setup() {
  arduboy.begin();
  power_twi_enable();
  wii.init();
}

void loop() {
  arduboy.clear();
  wii.poll();
  arduboy.setCursor(0, 0);
  arduboy.print("Z:");
  arduboy.print(wii.buttonZ());
  arduboy.print(" C:");
  arduboy.print(wii.buttonC());

  arduboy.setCursor(0, 8);
  arduboy.print("Joy X:");
  arduboy.print(wii.joyX());
  arduboy.print(" Y:");
  arduboy.print(wii.joyY());

  arduboy.setCursor(0, 16);
  if (wii.joyUp()) arduboy.print("Up");
  if (wii.joyDown()) arduboy.print("Down");
  if (wii.joyLeft()) arduboy.print("Left");
  if (wii.joyRight()) arduboy.print("Right");
  arduboy.display();
}