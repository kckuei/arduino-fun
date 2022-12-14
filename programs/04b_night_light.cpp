// Setup constants for baud rate, and pins we are using as inputs and outputs. 
const int baudRate = 9600;
const int sensorPin = A2;
const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

// Max value constant that controls the how the LED brightens.
const int maxVal = 50;

// Initialize variables to store sensor reading as well as light level of LED.
int maxLEDValue = 0;
int sensorValue = 0;


void setup() {
  // Setup serial port. 
  Serial.begin(baudRate);

  // Set the direction of the digital pins. 
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}


void loop() {
  // Read value of light sensor. Use a small delay to allow ADC to complete read.
  sensorValue = analogRead(sensorPin);
  delay(5);

  // Report the sensor readings to the computer. 
  Serial.print("Raw Sensor Value: ");
  Serial.println(sensorValue);

  // Hacky way to convert the sensor reading to a LED value.
  // We want the LED brightness to increase as the sensorValue diminishes to zero.
  // Calibrate by setting the  maxLEDValue constant.
  LEDValue = sensorValue;
  LEDValue = maxLEDValue - LEDValue;
  if (LEDValue < 0) {
    LEDValue = 0;
  } else if (LEDValue > maxLEDValue) {
    LEDValue = maxLEDValue;
  }

  // Report the calculated LED light level values.
  Serial.print("Mapped Sensor Value: ");
  Serial.println(LEDValue);

  // Set the LED light levels. 
  // All of the pins are mapped to the same light sensor.
  analogWrite(redLEDPin, LEDValue);
  analogWrite(greenLEDPin, LEDValue);
  analogWrite(blueLEDPin, LEDValue);
}
