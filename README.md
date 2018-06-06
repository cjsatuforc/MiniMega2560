# MiniMega2560 Project

This is my first project on GitHub so it will appear a little rough until I get up to speed.

This is my build of a Mini Mega2560 board. It uses the Mega2560 cpu with a CP2104 USB interface. The reason that I made this board was I wanted a more ports and memory for Arduino projects and I wanted a 3.3 volt Mega2560 that could be used with a breadboard.

Left board is 5 Volts version, right board is 3.3 Volts version.
![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/MiniMega2560both.png "MiniMega2560 Board")

The board uses an Atmel mega2560 CPU that can run Arduino (with the correct bootloader installed).
The board can be built as a 3.3 volt 8 MHz or a 5 volt 16 MHz system.
You can use the Arduino Mega2560 bootloader for the 5 volt 16 MHz build, the 3.3 volt 8 MHz system needs to have the fuse set for a External 8 MHz clock, I used MegaCore for that which can be found here on GitHub. It was very easy for me to use.

The board can be found at OSH Park. https://oshpark.com/shared_projects/cue1DDEi with project name MiniMega2560.

Schematic file:

Board file:

BOM file:

Arduino MiniMega2560 3.3 volt/8 MHz Board/CPU settings. I only needed to change the clock settings to 8 MHz external.

![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/MegaCore_Settings.png "MegaCore Settings")

Note: You can use a 5 volt Arduino UNO to burn bootloader for the 3.3 volt mega2560 system board.

Settings to enable TX RX Toggle Leds on CP2104 with Simplicity Studio.

![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/cp2104_enable_leds.png "CP2104 LEDs")

First time run error with Simplicity Studio on my iMac.

![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/Simplicity_ERROR2.png "Simplicity Error")

This error happened the first time I tried to read the settings on the cp2104 chip on my iMac.
I changed directory to cp210xcfg program and found it was missing execute permission. I added execute permission and restarted Simplicity, all then worked OK.

I always read the cp2104 settings first, then change the flags for TX RX toggle, then program the cp2104.
