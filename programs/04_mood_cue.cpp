// Include for servo library.
#include <Servo.h>

// Instantiate servo object.
Servo myServo;

// Set up name constant for potentiometer pin, and analog input, and servo range min/max bounds.
int const potPin = A0;
int const ANALOG_MIN = 0;
int const ANALOG_MAX = 1023;
int const SERVO_MIN = 0;
int const SERVO_MAX = 179;

// Declare variables.
int potVal;
int angle;

void setup() {
  // Associate the servo object with the Arudino digital pin 9.
  myServo.attach(9);

  // Initialize serial port for commuication.
  Serial.begin(9600);
}

void loop() {
  // Read the potentiometer values, and return values to computer.
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  // Map the potentiometer value to the servo values, and return values to computer.
  angle = map(potVal, ANALOG_MIN, ANALOG_MAX, SERVO_MIN, SERVO_MAX);
  Serial.print(", angle: ");
  Serial.println(angle);

  // Rotate the servo, and add a small delay to allow servo to move.
  myServo.write(angle);
  delay(15);
}

