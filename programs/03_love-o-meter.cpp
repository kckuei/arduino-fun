// Initialize constants.
const int baudRate = 9600;        // Sets the baud rate for the serial port.
const int sensorPin = A0;         // Sets the temperature sensor pin.
const float baselineTemp = 20.0;  // Sets the baseline temperature for branching.

void setup() {
  // Open a serial port with the computer.
  Serial.begin (baudRate);

  // Initialize the digital pin directions and turn off. 
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // Read the temperature sensor.
  int sensorVal = analogRead(sensorPin);

  // Convert the ADC reading to voltage.
  float voltage = (sensorVal/1024.0) * 5.0;

  // Convert the voltage to temperature in degrees C.
  float temperature = (voltage - 0.5) * 100;

  // Send the raw sensor value, voltage, and temperature to the computer. 
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  Serial.print(", Volts: ");
  Serial.print(sensorVal);

  Serial.print(", degrees C: ");
  Serial.println(temperature);

  // Turn off LED's for a low temperature.
  if (temperature < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if ((temperature >= baselineTemp + 2) && (temperature < baselineTemp+4)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if ((temperature >= baselineTemp + 4) && (temperature < baselineTemp+6)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  // Add a small delay as reading values too quickly will make values appear erratic.
  delay(1);

}

