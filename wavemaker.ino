/*
Alternate voltage as a sine function between PWMA and PWMB
pins to drive the linuar actuator back and forth.

amplitude must be in the range [0, 1]. This is the fraction
of the input voltage to be applied. For example, if 
amplitude is 0.25 and we have a 12V input as the source, 
the motor will be driven with a sine 
in the range [-4, 4] V.
*/

#include <math.h>

// set paddle period [s]
const float period = 1.;

// set max amplitude
const float amplitude = 0.7;

// disable the motor after this many oscialltions
const int max_counts = 5;

// number of samples
const int N = 500;

// array to store the sine form
uint8_t sine[N] = {0};

// delay in microseconds between each PWM update
int us_to_delay = 1000000 * period / (float) N;

// named constants for the pins that we'll use
const int ENABLE_PIN=8;
const int PWMA_PIN=11;
const int PWMB_PIN=3;

int counter = 0; // oscillation counter

void setup() {
  
  // initialize the sine form in the range [0, 255]
  for (int i = 0; i <= N; i++){
    sine[i] = round(255 * (0.5 * (1. - sin((float)i / N * 2 * M_PI))));
  }
  
  // initialize pins
  pinMode(ENABLE_PIN, OUTPUT); // ENABLE pin
  pinMode(PWMA_PIN, OUTPUT); // PWMA
  pinMode(PWMB_PIN, OUTPUT); // PWMB
  
  digitalWrite(ENABLE_PIN, HIGH); // enable MegaMoto+
}

void loop() {
    
  // loop through
  for (int i = 0; i <= N; i++){
    analogWrite(PWMA_PIN, (int) (amplitude * sine[i]));
    analogWrite(PWMB_PIN, (int) (amplitude * (255 - sine[i])));
    delayMicroseconds(us_to_delay);
  }
  
  ++counter;
  
  if (counter == max_counts){
    digitalWrite(ENABLE_PIN, LOW); // disable MegaMoto+
  }
  
}
