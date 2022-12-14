// Arduino Uno microcontroller program to make a snazzy spaceship interface.


// Declares variables in mem.
int switchState = 0;

void setup() {
  // Initializes digital pins as either inputs or outputs.
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // Gets the switch state.
  switchState = digitalRead(2);
  
  // If the button is not pressed.
  if (switchState == LOW) {
    digitalWrite(3, HIGH);     // green LED
    digitalWrite(4, LOW);      // red LED
    digitalWrite(5, LOW);      // red LED
  }
  // Otherwise the button is pressed.
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
