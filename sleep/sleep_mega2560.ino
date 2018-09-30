/*
  File name: sleep_mega2560
  Last changed: 23 Sept 2018
  Version: 1.0
  cpu sleep mode sample for 3.3 volt 8 MHz MiniMega2560
  ~18.5 micro amps when sleeping
  ~14.6 milli amps when not sleeping (for this test)
  See sleep_pix1 and sleep_pix2 for board layout.
  Note: Power for the USB chip comes from USB not VCC of the MiniMega2560.
  WARNING: In battery mode, VCC is NOT 3.3 volts, VCC becomes whatever the battery voltage is.
  Four changes needed for using Battery mode on 3.3 volt version of MiniMega2560.
  1.  Remove ENA_REG jumber, this stops power going to the regulator.
  2.  Move Reg-VCC jumper to VCC-BAT or connect current meter between VCC and BAT pins
  3.  Remove solder jumper (JPW) from power LED.
  4.  Remove solder jumpers (JDA,JCL) for SDA and SCL lines.
  Unplug USB cable to get lowest power usage reading.
  Do not use a battery volatge above 5.5 voltages!!
  Brown out is 2.7 volts for most setups, So battery from 2.8 to 5.4 volts should be good.
  This code for educational use only.
*/

// https://playground.arduino.cc/Learning/arduinoSleepCode

#include <avr/sleep.h>

#define LED 13
#define INTPIN 2                  // Interrupt 0 on pin 2, PE4 for mega2560 cpu

void setup() {
  Serial.begin(9600);
  delay(500);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);         // LED is on when cpu is awake
    
  pinMode(INTPIN,INPUT_PULLUP);
  ADCSRA = 0;                     // turn off ADC, this will reduce power needs.
  Serial.println("Setup Done");
  Serial.flush();
}


void theInterrupt()
{
  sleep_disable();
  detachInterrupt( digitalPinToInterrupt(INTPIN) );
}


// https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/

void doCpuSleep()        // go to sleep if INTPIN is high, wake when INTPIN is low
{
  Serial.println("Going to sleep");
  Serial.flush();
  delay(100);
  digitalWrite(LED,LOW);
  sleep_enable();
  attachInterrupt( digitalPinToInterrupt(INTPIN) , theInterrupt, LOW);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);     // there many sleep modes, this is just one sample
  sleep_cpu();
  Serial.println("Now awake");
  digitalWrite(LED,HIGH);
}


void loop() {
 delay(50);
 if (digitalRead(INTPIN) == 1) doCpuSleep();
}

