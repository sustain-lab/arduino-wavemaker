# arduino-wavemaker

Powering a wave paddle motor with Arduino Uno.

## Parts

* [Arduino Uno](https://store.arduino.cc/usa/arduino-uno-rev3)
* [MegaMoto+](http://www.robotpower.com/products/MegaMotoPlus_info.html) H-bridge shield from Robot Power
* [Linear actuator](https://www.progressiveautomations.com/mini-linear-actuator) from Progressive Automations
* 12V power supply

## Getting started

### Get the code

```
git clone https://github.com/sustain-lab/arduino-wavemaker
```

### Generating the signal

[This notebook](https://github.com/sustain-lab/arduino-wavemaker/blob/master/wavemaker_signal.ipynb)
describes how we generate the sign signal in the range [0-255] to send to the motor.
The notebook is for the purpose of illustration. The actual values are computed on the Arduino itself
at the start of the program.

### Arduino code

See the full code [here](https://github.com/sustain-lab/arduino-wavemaker/blob/master/wavemaker.ino).

We can currently control:

* Period [s]
* Amplitude (fraction voltage of power source)
* Number of oscillations to perform before stopping

## Resources

* [MegaMoto+ user manual](http://www.robotpower.com/downloads/MegaMoto-user-manual.pdf)

## Thanks

* Cedric Guigand
