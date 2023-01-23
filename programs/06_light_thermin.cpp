//  Creates variables for calibrating sensor.
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

// Names constant for calibration indicator.
const int ledPin = 13;

void setup() {
  // Sets digital pin direction and turns it to high.
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // Uses while loop for calibration over 5000 ms. 
  // millis() returns the number of ms since board has started running.
  while (millis() < 5000) {
    // Calibrates the minimum and maximum sensor values. 
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // Turns off LED to indicate calibration has finished.
  digitalWrite(ledPin, LOW);
}
duration
void loop() {
  // Reads and store the phototransistor sensor value.
  sensorValue = analogRead(A0);

  // Maps the sensor value to a frequency.
  // I.e., sensor low/high range to frequency 50/2000 Hz range.
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 2000);

  // Plays the frequency on pin 8, with pitch, duration 20 ms.
  tone(8, pitch, 20);
  delay(10);
}

