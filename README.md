# Arduino Projects
Documents my first foray and some working notes into microcontroller programming using the Arudino Uno Starter Kit.

# Setup
In addition to the project manual, these docs were helpful with getting started:
* [Getting Started with Arduiono IDE 2.0](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started-ide-v2)
* [Functions Reference](https://www.arduino.cc/reference/en/

## Arduino IDE 2.0 Installation
* I used the appImage installation option for `linux`
* Don't forget to enable permissions to run: `Properties > Permissions > Execute: > Click Allow executing file as program`


## Error on Blink Demo
One issue I encountered with uploading programs using the IDE:

```
Sketch uses 924 bytes (2%) of program storage space. Maximum is 32256 bytes.
Global variables use 9 bytes (0%) of dynamic memory, leaving 2039 bytes for local variables. Maximum is 2048 bytes.
avrdude: ser_open(): can't open device "/dev/ttyACM0": Permission denied
Failed uploading: uploading error: exit status 1
```

And the [resolution](https://askubuntu.com/questions/1056314/uploading-code-to-arduino-gives-me-the-error-avrdude-ser-open-cant-open-d
):

In root:
```bash
sudo chmod a+rw /dev/ttyACM0
```

# Projects

## 01. Get to Know Your Tools
An electricity/circuits refresher, and primer of how breadboards work.

### Concepts
* transducers = convert other forms of energy to electrical energy or vice versa
* sensors = convert other forms of energy to electrical energy
* actuators = convert electrical energy to other forms
* circuits = are closed loop systems that convey electricity from a power source (e.g. battery) to something that does something useful (load)
* power flows from high to low potential
* ground generally point of least potential energy
* in DC circuits, flow is unidirectional
* in AC circuits, flow changes direction every 50 or 60 Hz
* current = amount of charge flowing past a point in circuit (amps)
* voltage = difference in energy between a point in a circuit and another (V)
* resistance = how much a component resists flow of current (ohms)
* V (voltage) = I (current) * R (resistance)
* Breadboard = protoyping board for building circuits that doesn't require soldering. Consists of multiple horizontal/vertical rows of conductive metal strips with wells that you can easily plug into.
* reading resistor bands
  * are either 4 or 5-band
  * the band colors are color-coded to digits
  * for 4-band resistors
    * 1st band = 1st digit
    * 2nd band = 2nd digit
    * 3rd band = number of trailing zeros/multiplier
    * 4th band = tolerance

### Building a Simple, Series, and Parallel Circuit

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


## 02. Spaceship Interface
A digital I/O to mimic those snazzy 1970s sci-fi spaceship interfaces.

<img src="./assets/02/picard.jpg" alt="Picard Engage" width="300" />

### Concepts
* Skech = an Arduino computer program. Every sketch has two main functions: a `setup()` and `loop()` function. 
* The `setup()` function is run once at the start of the program, and the `loop()` function is run repeatedly like a while loop.
* The digital pins on the Arduino board can be used to listen for or recieve a signal (i.e. what is the state?) or trigger a response (i.e. set the state). The response is binary, i.e. it is either on/off (or low/high in terms of voltage).
* Use `pinMode()` to configure the digital pins as either inputs or outputs in `setup()`.
* Use `digitalRead()` to read a state (e.g., listen for a signal like a button push).
* Use `digitalWrite()` to set the state of a digital pin (e.g., light up a button).
* Use `delay()` to halt execution of the code for a set duration.

### Beep-Boop

<table>
  <theader>
    <tr>
      <th>Press Button</th>
      <th>Toggle Button</th>
    </tr>
  </theader>
  <tbody>
    <tr>
      <td><img src="./assets/02/beeboop.gif" width="200" /></td>
      <td><img src="./assets/02/beeboop2.gif" width="200" /></td>
    </tr>
  </tbody>
</table>

[Microcontroller Program.](https://github.com/kckuei/arduino-fun/blob/main/programs/02_spaceship_interface.cpp)


## 03. Love-O-Meter
Registers how hot you are.

### Concepts
* Arudino has a build-in analog-to-digital convert (ADC).
* Analog pins 0-5 report a value between 0-1023, which maps to a range from 0 to 5 volts.
* Use the `Serial.begin()` command in `setup()` to open up a serial port to communicate with the cpu.
* Then you can use `Serial.print` or `Serial.println` to log values.

### These Hands were Made for Hold'n

<table>
  <theader>
    <tr>
      <th>Temperature Meter</th>
    </tr>
  </theader>
  <tbody>
    <tr>
      <td><img src="./assets/03/thermistor.gif" width="200" /></td>
    </tr>
  </tbody>
</table>

[Microcontroller Program.](https://github.com/kckuei/arduino-fun/blob/main/programs/03_love-o-meter.cpp)


## 04. Color Mixing Lamp
Create a lamp that smoothly changes colors based on external lighting conditions using a tri-color LED and three phototransistors. 

### Concepts
* phototransistors = components that generate a current proportional to quantity of light absorbed. 
* LED = light-emitting diode, emits light when current/voltage is applied.
* A fading LED effect can be achieved by either directly manipulating the applied voltage, or using pulse width modulation (PWM). 
* The output of the Arudiono is non-variable constant 5V voltage, therefore need PWM to achieve this affect.
* How it works: 
  * PWM rapidly turns the output to `HIGH` and `low` over a fixed period of time. Rapidly turning the pin `HIGH` and `LOW` emulates a changing voltage, perceptually akin to frames in a movie.
  * Duty cycle = the percentage of time that a pin is `HIGH` in a period.
  * A pin that is `HIGH` half of the time, and `LOW` the remaining time has a duty cycler of 50%.
  * The lower the duty cycle, the dimmer the LED.
* Programatically, the duty cycle is set by passing a second argument to `digitalWrite()`.
* To measure the relative amount of red, green, or blue, we can apply filters to the individual phototransistors. E.g.m, red filter passes only red light, green filter only passes green light, etc.


<table>
  <theader>
    <tr>
      <th>Kinda Moody</th>
      <th>Red to Blue</th>
    </tr>
  </theader>
  <tbody>
    <tr>
      <td><img src="./assets/04/mood1.gif" width="200" /></td>
      <td><img src="./assets/04/mood2.gif" width="200" /></td>
    </tr>
  </tbody>
</table>

[Microcontroller Program.](https://github.com/kckuei/arduino-fun/blob/main/programs/04_color_mixing_lamp.cpp)

### Variant: A Nightlight to Keep Scary Monsters Away
It brightens as the external lighting fades:
* Uses the same tri-color LED and one phototransistor.
* Interestingly, the response and calibration/fudge factor is sensitive to the orientation of the phototransistor with respect to the light source.
* For best results, it's probably best to use a 2-3 phototransistors oriented at different angles, and then take the average of their sensor values for a less biased result.
* The LED itself also emits light which the phototransistor may be picking up, so it may be a good idea to isolate/obscure the line of sight of the phototransistor from the LED.

<table>
  <theader>
    <tr>
      <th>On/Off</th>
      <th>Gradual Fade In/Out</th>
    </tr>
  </theader>
  <tbody>
    <tr>
      <td><img src="./assets/04b/04b_nightlight1.gif" width="200" /></td>
      <td><img src="./assets/04b/04b_nightlight2.gif" width="200" /></td>
    </tr>
  </tbody>
</table>

[Microcontroller Program.](https://github.com/kckuei/arduino-fun/blob/main/programs/04b_night_light.cpp)


## 05. Mood Cue
Uses a servo motor to make a mechanical guage to point to the mood for the day.

### Concepts
* Servo motors = motors that move to a specific position, typically a 0-180 degree range of motion.
* Similar to PWM in LED's, servos expect a number of pulses to tell them what angle to move to. 
  * Pulses vary between 1000 and 2000 microseconds
  * Arudiono comes with a `Servo.h` library for controlling the motor
* Use `map` to map/change the scale of the analog input from 0-1023 to 0-180 degrees. 
* *Decoupling capacitors* are used to reduce, decouple changes caused by components from the rest of the circuit (e.g. voltage drops from drawing more current due to already being in motion)
* Capacitors are directional, and also have a cathode/anode side. 
* `CAUTION:` **Putting capacitors in backwards can make them explode**.


<table>
  <theader>
    <tr>
      <th>Testing Testing</th>
      <th>:) :| :) :|</th>
    </tr>
  </theader>
  <tbody>
    <tr>
      <td><img src="./assets/05/05_mood_cue1.gif" width="200" /></td>
      <td><img src="./assets/05/05_mood_cue2.gif" width="200" /></td>
    </tr>
  </tbody>
</table>

[Microcontroller Program.](https://github.com/kckuei/arduino-fun/blob/main/programs/05_mood_cue.cpp)

Note: 
The servo signal and power wires (white and red wires) are reversed compared to the manual.

<img src="./assets/05/servo_wire_mismatch.jpg" width="200" />


### Variant: Decision-Maker
Push a button and have it pick a choice for you (yes, no, maybe)

### Idea: Disco Board
Tiny discoteque light board to impress the ladies

<img src="./assets/disco/discoboard.jpg" width="200" />


## 06. Light Theremin
Uses a phototransistor and a piezo element to make a light-based theremin. 

### Concepts
* *theremin* is an instrument that makes sounds based on nearby movements, e.g. musician's hands.
* *piezo* is a small element that vibrates when it recieves electricity; the displacement of air hence creates sound waves.
* We use the `map()` function to map the light intensity from a phototransistor to a pitch or frequency. That frequency or pitch is then specified in a `tone()` function that manipulates the sound emitted from the piezo: hence the 'light thermin'.
* `millis()` returns the number of ms elapsed since start of program.  We use it to add a calibration state in the setup by mapping the min/max phototransistor values representative of someone playing the light thermin.
* `tone()` is a function that can be used to play a sound (given a pin), that takes a pitch and duration.

[Video placeholder]

[Microcontroller Program.](https://github.com/kckuei/arduino-fun/blob/main/programs/06_light_thermin.cpp)


## 07. Keyboard Instrument
Uses a few resistors and buttons to build a musical keyboard.

### Concepts
* *resistor ladder* is a technique for reading a number of switches using the analog input; consists of arranging several switches in parallel; each button when pressed engages a different number of resistors and hence voltage level, which gets passed/read to the input analog pin. 
* Each of the switches acts as a voltage divider.

[Video placeholder]

[Microcontroller Program.](https://github.com/kckuei/arduino-fun/blob/main/programs/07_keyboard_instrument.cpp)


## 08. Digital Hourglass
Uses a tilt sensor, array of LED's, some resistors, and Arduino's built-in timer to build a digital hourglass.

### Concepts
* 


