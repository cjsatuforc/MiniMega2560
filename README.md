# MiniMega2560 Project

29 Sept 2018 - Updated info for new version of board that can now be configed to use sleep mode using battery (no voltage reg for sleeping). Solder jumpers were added to disable Power LED and I2C pullups. I will add more info on this board as I have time.

This is my build of a MiniMega2560 board. It uses the Mega2560 cpu with a CP2104 USB interface. The reason that I made this board was I wanted a more ports and memory for Arduino projects and I wanted a 3.3 volt Mega2560 that could be used with a breadboard.

The project now has several boards for the MiniMega2560 board the can run Arduino.
1. Network card using the W5500 chip.
2. 3.3 volt PoE module for the network card.
3. Adafruit feather adapter board.
4. General prototype board.
5. Data logger board (Clock, 32K Fram memory, and SD Micro card support).
6. WiFi board. The MiniMega2560v01_WiFi now has code for testing NetCard to WiFi Card via serial link.

The WiKi has info on how I test my boards.

I am designing a GRBL CNC board at this time so I can make solder past stencils. I will post that board also when done.

The bare board can be found at OSH Park. https://oshpark.com/shared_projects/yTyv53VL with project name MiniMega2560v10_2e.

Schematic file: MiniMega2560v10_2e.SC.pdf

Board file: MiniMega2560v10_2e_BD.pdf

BOM file: MiniMega2560v10_2e.BOM.pdf

Left board is 5 Volts version, right board is 3.3 Volts version.
![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/MiniMega2560both.png "MiniMega2560 Board")

The board uses an Atmel mega2560 CPU that can run Arduino (with the correct bootloader installed).
The board can be built as a 3.3 volt 8 MHz or a 5 volt 16 MHz system.
You can use the Arduino Mega2560 bootloader for the 5 volt 16 MHz build, the 3.3 volt 8 MHz system needs to have the fuse set for a External 8 MHz clock, I used MegaCore for that which can be found here on
GitHub https://github.com/MCUdude/MegaCore It was very easy for me to use.

Note: I use a 5 volt power source for the 3.3 volt MiniMega2560 cpu.

Arduino MiniMega2560 3.3 volt/8 MHz Board/CPU settings. I only needed to change the clock settings to 8 MHz external.

![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/MegaCore_Settings.png "MegaCore Settings")

Note: You can use a 5 volt Arduino UNO to burn the bootloader for the 3.3 volt mega2560 system board.


Settings below show how to enable TX RX Toggle Leds on CP2104 with Simplicity Studio.

https://www.silabs.com/products/development-tools/software/simplicity-studio

![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/cp2104_enable_leds.png "CP2104 LEDs")

First time run error with Simplicity Studio on my iMac.

![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/Simplicity_ERROR2.png "Simplicity Error")

This error happened the first time I tried to read the settings on the cp2104 chip on my iMac.
I changed directory to cp210xcfg program and found it was missing execute permission. I added execute permission and restarted Simplicity, all then worked OK.

I always read the cp2104 settings first, then change the flags for TX RX toggle, then program the cp2104.

https://www.silabs.com/documents/public/data-sheets/cp2104.pdf

##########  Note: I have posted several other boards to work with this Arduino project.  ##########

Mounting/Inserting the MiniMega2560 cpu into a breadboard is a little different. The pin rows are 1.100 inches apart. To mount the board I do it like the picture below shows.

![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/MiniMega2560_BreadBoardMnt.jpg "MegaCore Breadboard")

Why the 6 pins at the back end of the board? These pins do not align with breadboards and are not normally used (at least by me). I am building a GRBL/CNC board to make stencils and GRBL needs the extra pins. If you want to use the pins with a breadboard, solder them in and then bend them 90 degrees, then use jumpers to connect them to the breadboard like the picture below shows.

![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/BackPins1.jpg "MegaCore 6 pins")
![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/BackPins2.jpg "MegaCore 6 pins")

This is my bootloader fixture I use to install the Arduino boot code. It works for both the 3.3 volt and 5 volt systems. There are many different ways to wire up for burning the bootloader, I just got tired doing the wire up for each board. If I have time later I will post how to make this unit.

![alt text](https://github.com/Sd4Projects/MiniMega2560/blob/master/BootBurnerJig.jpg "Boot burner jig")
