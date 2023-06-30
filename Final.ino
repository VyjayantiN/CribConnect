#include <Servo.h>

const int soundSensorPin = 2; // Pin connected to the sound sensor
const int servoPin = 9;       // Pin connected to the servo motor

Servo servoMotor;  // Create a servo object
int servoPosition = 90;  // Initial position of the servo motor

void setup() {
  pinMode(soundSensorPin, INPUT);  // Set the sound sensor pin as an input
  servoMotor.attach(servoPin);     // Attach the servo motor to the pin
}

void loop() {
  int soundValue = digitalRead(soundSensorPin);  // Read the sound sensor value

  if (soundValue == HIGH) {  // If the sound sensor detects a high sound level (baby crying)
    servoPosition = (servoPosition == 0) ? 270 : 0;  // Toggle the servo position

    servoMotor.write(servoPosition);  // Move the servo to the new position
    delay(500);                      // Wait for 1 second before reversing the servo
  }
}
