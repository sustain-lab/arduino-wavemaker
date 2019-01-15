#!/bin/bash
#
# Sets up permissions for the serial 
# connection with the Arduino board. 
# User must be on sudoers list.

sudo usermod -a -G dialout $(whoami)
sudo chmod a+rw /dev/ttyACM0
