/*
  TinyOzSLIM.h - 0.96' I2C 128x64 OLED Driver Library
  2014 Copyright (c) OscarLiang.net  All right reserved.
 
  Author: Oscar Liang
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  
 
  Uses TinyWireM instead of Wire llibrary. For Attiny processors
  Change done by Andreas Spiess, sensorsiot@gmail.com
  Condensed For Attiny processors to be used as diagnostic tool using I2C with OLED
  Change done by Jackie Thomas, jackiethomaz@gmail.com

*/

#ifndef OzSLIM_data_H
#define OzSLIM_data_H

#include <Arduino.h>



#define OzSLIM_Max_X					128	//128 Pixels
#define OzSLIM_Max_Y					64	//64  Pixels

#define OLED_ADDRESS					0x3C
#define I2C_400KHZ						1	// 0 to use default 100Khz, 1 for 400Khz

// registers
#define OzSLIM_COMMAND_MODE				0x80
#define OzSLIM_DATA_MODE				0x40

// commands

#define HORIZONTAL_ADDRESSING	0x00
#define PAGE_ADDRESSING			0x02




class OzSLIM {

public:
//OLED BELOW
	byte addressingMode;
    void init();
	void sendCommand(byte command);  //sends command to I2C
	
	void sendData(byte Data);   //sends data to I2C

	void printChar(char c, byte X=255, byte Y=255);  //called by all displays except bitmap
	
	void printString(const char *String, byte X=255, byte Y=255, byte numChar=255);  //prints initialize and start DHT11
	
	void printBigNumber(const char *number, byte column=0, byte page=0, byte numChar=255); //prints temp, humidity
	
    void drawBitmap(const byte *bitmaparray, byte X, byte Y, byte width, byte height);  //draws WORDS TEMP AND HUMIDITY
   
	
	
	void setCursorXY(byte Column, byte Row);  //set cursor on OLED
	
	void clearDisplay();          //clear display OLED
	void clearPage(byte page);    //clear just the page OLED
	

	void initForHeartBeat(int pinHB, int delayTime);  //for heartbeat LED
	void initOled(int delayTimeOLED);
	void initDHT11(int delayTimeDHT11);
	void getTemp(int dht_apin, int dht11DelayTime);

 
	
};

extern OzSLIM OzSlim;  // OzSLIM object 

#endif


