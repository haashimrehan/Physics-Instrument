/*
 * 5/27/2019
 * By: Haashim Rehan
 * Takes an angle input and translates it to a frequency 
*/

// Libraries for gyro
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

int angle = 0; // Holds the value for the angle of the glove (-180 to 180)
MPU6050 mpu; // holds all gyro data
boolean pressed = false; // Stores whether the touch sensor is pressed

void setup() {
  gyroSetup();
  pinMode(3, INPUT_PULLUP); // Sets pin 3 as an input (used for touch sensor)
}

void loop() {
  gyroUpdate(); // Updates the angle variable to the right angle
  pressed = !digitalRead(3); // update the state of the touch sensor

  // map the angle from the gyro, to the pitches we want to hear.
  int pitch = map(angle, -90, 90, 300, 2000); //Mapped to 300Hz to 2000Hz

  // Set the endpoints for the pitches (Sets a limit on min and max frequency)
  pitch = constrain(pitch, 300, 2000);

  if (pressed) { // If the touch sensor is pressed, play the tone
    // Play a tone on pin 8 with a frequency of 'pitch' and a duration of 40ms
    tone(8, pitch, 40);
    delay(1);
  } else { // Otherwise, don't play anything
    noTone(8);
    delay(100);
  }
}
