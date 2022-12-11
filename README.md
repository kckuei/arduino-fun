# Arduino Experiments
## About
* Some notes from my first foray working with and programming microcontroller devices 
* Explores the Arudino (Uno) Starter Kit and provided tutorials, and other amateur shenanigans

## Setup
In addition to the project manual, these docs were helpful with getting started:
* [Getting Started with Arduiono IDE 2.0](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started-ide-v2)

### Arduino IDE 2.0 Installation
* I used the appImage installation option for `linux`
* Don't forget to enable permissions to run: `Properties > Permissions > Execute: > Click Allow executing file as program`


### Error on Blink Demo
One issue I encountered with uploading programs using the IDE:

```
Sketch uses 924 bytes (2%) of program storage space. Maximum is 32256 bytes.
Global variables use 9 bytes (0%) of dynamic memory, leaving 2039 bytes for local variables. Maximum is 2048 bytes.
avrdude: ser_open(): can't open device "/dev/ttyACM0": Permission denied
Failed uploading: uploading error: exit status 1
```

And the [resolution](https://askubuntu.com/questions/1056314/uploading-code-to-arduino-gives-me-the-error-avrdude-ser-open-cant-open-d
):

```
(base) kckuei@kckuei-Precision-3560:~$ ls /dev/ttyACM0
/dev/ttyACM0
(base) kckuei@kckuei-Precision-3560:~$ sudo chmod a+rw /dev/ttyACM0

```

## Notes

### 01 Get to Know Your Tools
Electricity and circuits refresher, and how breadboards work.

#### Concepts
* transducers = other forms of energy to electrical energy or vice versa
* sensors = other forms of energy to electrical energy
* actuators = electrical energy to other forms
* circuits = closed loop systems that convey electricity from a power source (e.g. battery) to something that does something useful (load)
* power flows from high to low potential
* ground generally point of least potential energy
* in DC circuits, flow is unidirectional
* in AC circuits, flow changes direction every 50-60Hz.
* current = amount of charge flowing past a point in circuit (amps)
* voltage = difference in energy between a point in a circuit and another (V)
* resistance = how much a component resists flow of current (ohms)
* V (voltage) = I (current) * R (resistance)
* breadboard = protoyping board for building circuits that doesn't require soldering. consists of multiple horizontal/vertical rows of conductive metal strips.
* reading resistor bands: either 4 or 5-band, is color-coded to digits, shows digits followed by number of trailing zeros/multiplier, and lastly tolerance value.

#### Building a Simple, Series, and Parallel Circuit

<table>
  <theader>
    <tr>
      <th>Simple Circuit</th>
      <th>Series Circuit</th>
      <th>Parallel Circuit</th>
    </tr>
  </theader>
  <tbody>
    <tr>
      <td><img src="./assets/01/simple.gif" width="200" /></td>
      <td><img src="./assets/01/series.gif" width="200" /></td>
      <td><img src="./assets/01/parallel.gif" width="200" /></td>
    </tr>
  </tbody>
</table>


### 02 Spaceship Interface
Digital input and output to make a snazzy spaceship interface like out of a 1970s sci-fi movie. 

**Placeholder for Star Trek Piccard "Engage"**

#### Concepts
* The digital pins on the Arduino board can be used to recieve a signal or trigger a response (i.e., set a state).
* The response is binary, i.e. it is either on/off (or low/high in terms of voltage).
* `digitalRead()` is used to read a state (e.g., recieve a signal like a button push).
* `digitalWrite()` is used to to set the state of a digital pin (e.g., light up a button).
* Skech = an Arduino computer program. Every sketch has two main functions: a `setup()` and `loop()` function. 
* The `setup()` function is run once at the start of the program, and the `loop()` function is run as a while loop.
* `pinMode()` is used to configure/initialize the digital pins as either inputs or outputs during `setup()`.
* Use `delay()` to trigger a time delay.

#### Microcontroller Program

```C++
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
    digitalWrite(3, HIGH);	// green LED
    digitalWrite(4, LOW); 	// red LED
    digitalWRite(5, LOW);	// red LED
  }
  // Otherwise the button is pressed.
  else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWRite(5, HIGH);
    delay(250);
    
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
  }
}

```



