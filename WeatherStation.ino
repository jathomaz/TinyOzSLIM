/***********************!!!!!!!!!!!!!!!!!!! 
NOTE CHANGED FUSE FOR 8Mhz in attiny85
DISPLAY IN OLED IS SLOW AT 1MHZ!!!!!!!!!!
***********************!!!!!!!!!!!!!!!!!!!*/ 
#include <TinyWireM.h>
#include <USI_TWI_Master.h>
#include <TinyOzSLIM.h>
#include "BIGTEMP.h"     //bitmap for the word TEMP
#include "HUMIDITY.h"   //bitmap for the word HUMIDITY
#include "dht.h"
// PIN1 RESET       (tiny reset)         PIN8         (tiny 5V)
// PIN2 pinHeartbeat(tiny p3)            PIN7         (tiny 2) SCK -  SCL
// PIN3 DHTPIN      (tiny p4             PIN6         (tiny 1) MISO 
// PIN4 GND         (tiny GND)           PIN5         (tiny 0) MOSI - SDA
//#define  dht_apin 3
//#define  pinHB  4

int delay_time = 1500;
//dht DHT;   // instance


void setup() {
  
  
   OzSlim.initForHeartBeat(2, 500); //turn the LED on pin 2 on delay time, turn off                    
   OzSlim.initOled(500);            // housekeeping on OLED
   OzSlim.initDHT11(1000);          // housekeeping on DHT11 prints to OLED       
  }

void loop() {
   OzSlim.getTemp(3, 500);   //get temp reading from pin 3 and loop ever

}
