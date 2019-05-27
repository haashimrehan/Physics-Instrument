#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

int angle = 0;
MPU6050 mpu;
boolean pressed = false;

void setup() {
  gyroSetup();
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  gyroUpdate();
  pressed = !digitalRead(3);
  int pitch = map(angle, -90, 90, 300, 2000);
  pitch = constrain(pitch, 300, 2000);
  Serial.println(pitch);
  if (pressed) {
    tone(8, pitch, 40);
    delay(1);
  } else {
    noTone(8);
    delay(100);
  }
}
