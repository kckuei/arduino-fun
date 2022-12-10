# About
* My first foray with working on microcontroller devices and  programming for building digital devices
* Documents my experience with using the Arudino (Uno) Starter Kit and working through tutorials, and random personal projects


## Setup
In addition to the manual, these docs were helpful:
* [Getting Started with Arduiono IDE 2.0](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started-ide-v2)

### Arduino IDE 2.0 Installation
* Used the AppImage installation option for Linux
* Must enable permissions to run: `Properties > Permissions > Execute: > Click Allow executing file as program`


### Error on Blink Demo
One issue when trying to upload programs:

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
* reading resistor bands: either 4 or 5-band, color-coded to digits and number of trailing zeros/multiplier, and tolerance value.

#### Simple Circuit

[Simple Circuit](./assets/01/simple.gif)

#### Series Circuit

[Series Circuit](./assets/01/series.gif)

#### Parallel Circuit

[Parallel Circuit](./assets/01/parallel.gif)

### 02 Spaceship Interface

