// Arduino Uno microcontroller program to make a snazzy spaceship interface.
// This version lets you toggle the button instead, but sometimes doesn't register depending if
// the hold down coincides with a delay.


// Declares variables in mem.
int switchState = 0;
int engaged = 0;

void setup() {
  // Initializes digital pins as either inputs or outputs.
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  // initialize baud rate, which represents the maximum bits per seconds that can be transferred.
  Serial.begin(9600);
}

void loop() {
  // Gets the switch state.
  switchState = digitalRead(2);

  if ((switchState == HIGH) && (engaged == 0)) {
    engaged = 1;
  }
  else if ((switchState == HIGH) && (engaged == 1)) {
    engaged = 0;
  }
  delay(250);
  
  // If the warp drive is not engaged.
  if (engaged == 0) {
    digitalWrite(3, HIGH);	// green LED
    digitalWrite(4, LOW); 	// red LED
    digitalWrite(5, LOW);	// red LED
  }
  // Otherwise warp drive is engaged.
  else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250);
    
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);

    digitalWrite(3, LOW);
    digitalWrite(3, HIGH);
    delay(25);
    digitalWrite(3, LOW);
    digitalWrite(3, HIGH);
    delay(25);
  }
}
