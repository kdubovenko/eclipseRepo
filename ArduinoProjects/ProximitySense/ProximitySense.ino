/*
  WriteMultipleVoltages
  
  Reads analog voltages from pins 0-7 and writes them to the 8 fields of a channel on ThingSpeak every 20 seconds.
  
  ThingSpeak ( https://www.thingspeak.com ) is an analytic IoT platform service that allows you to aggregate, visualize and 
  analyze live data streams in the cloud.
  
  Copyright 2017, The MathWorks, Inc.
  
  Documentation for the ThingSpeak Communication Library for Arduino is in the extras/documentation folder where the library was installed.
  See the accompaning licence file for licensing information.
*/

#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include "IFTTTMaker.h"
#include "BlynkSimpleEsp8266.h"
#include "TimeLib.h"
//#include "WidgetRTC.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

#define BUF_SIZE      200
#define MIN_BUF_SIZE  60

char ssid[] = "KonstaCat"; //  your network SSID (name) 
char pass[] = "0223#tpa";   // your network password

//Thingspeak stuff

#define KEY "cK9gQ8qgo_F1f1SHy3iCP"  // Get it from this page https://ifttt.com/services/maker/settings
#define LIGHTS_ON_EVENT "lifx_light_on" // Name of your event name, set when you are creating the applet
#define LIGHTS_OFF_EVENT "lifx_light_off" // Name of your event name, set when you are creating the applet

//Blynk stuff

#include <BlynkSimpleEsp8266.h>
char auth[] = "b7b7ddd0a43943ddb5fd072cfc02eafc";
WidgetLED led1(V1);
WidgetLED led2(V5);
//WidgetRTC rtc;

//time stuff
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

//WiFiClient  client;
WiFiClientSecure client;
IFTTTMaker ifttt(KEY, client);

//custom automation stuff
#define ON	1
#define OFF	0
#define TIMEOUT_S	300 //5 min
#define UTC_OFFSET	(-7)
bool light_status = OFF;
unsigned int second_cnt = 0;
unsigned int TimeoutValue = 0;
unsigned int event_cnt = 0;

int status = WL_IDLE_STATUS;

volatile unsigned long next;
//unsigned int ADC_raw;
uint16_t millisecond_buffer[2][BUF_SIZE];
uint16_t buffer_cnt = 0;
uint16_t buffer_select = 0;
bool read_buffer = false;
uint32_t second_buffer[60];
uint16_t second_buffer_count = 0;


/*
  *****************************************************************************************
  **** Visit https://www.thingspeak.com to sign up for a free account and create
  **** a channel.  The video tutorial http://community.thingspeak.com/tutorials/thingspeak-channels/ 
  **** has more information. You need to change this to your channel, and your write API key
  **** IF YOU SHARE YOUR CODE WITH OTHERS, MAKE SURE YOU REMOVE YOUR WRITE API KEY!!
  *****************************************************************************************/
unsigned long myChannelNumber = 286926;
const char * myWriteAPIKey = "F1VW3ERE39QPBZN7";
IPAddress ip;


unsigned long getTime() {
	unsigned long epochTime;

	Serial.println("getting time...");
	timeClient.update();
	//Serial.println(timeClient.getFormattedTime());
	epochTime = timeClient.getEpochTime();
	return epochTime;
}

BLYNK_WRITE(V2)
{
	int tempval;
	tempval = (unsigned int)param.asInt(); // assigning incoming value from pin V1 to a variable
	// You can also use:
	// String i = param.asStr();
	// double d = param.asDouble();
	if(tempval == 1)
	{
		TimeoutValue = 5;
	}
	else if(tempval == 2)
	{
		TimeoutValue = 10;
	}
	else if(tempval == 3)
	{
		TimeoutValue = 30;
	}
	else if(tempval == 4)
	{
		TimeoutValue = 60;
	}
	else if(tempval == 5)
	{
		TimeoutValue = 120;
	}
	else if(tempval == 6)
	{
		TimeoutValue = 300;
	}
	Serial.print("Slider value is: ");
	Serial.println(TimeoutValue);
	led2.on();
}

BLYNK_WRITE(V3)
{
	int timeoutAssert;
	timeoutAssert = param.asInt(); // assigning incoming value from pin V1 to a variable
	// You can also use:
	// String i = param.asStr();
	// double d = param.asDouble();
	if(timeoutAssert)
	{
		TimeoutValue = 0;
		led2.off();
		Blynk.virtualWrite(V2, TimeoutValue);
	}
	Serial.print("Button value is: ");
	Serial.println(timeoutAssert);
}

BLYNK_WRITE(V7)
{
	int tempval;
	tempval = param.asInt(); // assigning incoming value from pin V1 to a variable
	// You can also use:
	// String i = param.asStr();
	// double d = param.asDouble();
	if(tempval)
	{
		event_cnt = 0;
	}
	Blynk.virtualWrite(V6, event_cnt);
}

void setup() {

  Serial.begin(115200);
//	WiFi.begin(ssid, pass);
//   ThingSpeak.begin(client);
  pinMode(5, INPUT);
	pinMode(16, OUTPUT);
	digitalWrite(16, HIGH);
	
	Blynk.begin(auth, ssid, pass);
	Blynk.virtualWrite(V2, TimeoutValue);
	
	setTime(getTime());
	
	String currentTime = String(hour()) + ":" + minute() + ":" + second();
	String currentDate = String(day()) + "/" + month() + "/" + year();
	Serial.print("Current time: ");
	Serial.print(currentTime);
	Serial.print(" ");
	Serial.print(currentDate);
	Serial.println();
	
// 	WiFi.mode(WIFI_STA);
// 	WiFi.disconnect();
// 	delay(100);
// 
// 	// Attempt to connect to Wifi network:
// 	Serial.print("Connecting Wifi: ");
// 	Serial.println(ssid);
// 	WiFi.begin(ssid, pass);
// 	while (WiFi.status() != WL_CONNECTED) {
// 		Serial.print(".");
// 		delay(500);
// 	}
// 	Serial.println("");
// 	Serial.println("WiFi connected");
// 	Serial.println("IP address: ");
	ip = WiFi.localIP();
	Serial.println(ip);
  
  Serial.println("Huzzah motion detect started");
	

}

void loop() {
	
	bool motion_det;
	motion_det = digitalRead(5);

	Serial.print("Motion sensor reading: ");
	Serial.println(motion_det);
	
	Serial.print("countdown: ");
	Serial.println(second_cnt);
	
	Blynk.virtualWrite(V8, second_cnt);
	
	if(TimeoutValue)
	{
		TimeoutValue--;
		if(TimeoutValue == 0)
		{
			led2.off();
			Blynk.virtualWrite(V2, TimeoutValue);
		}
	}
	else
	{
		if(motion_det)
		{
			Blynk.virtualWrite(V6, event_cnt);
			second_cnt = TIMEOUT_S;
			if(light_status == OFF)
			{
				event_cnt++;
				led1.on();
				light_status = ON;
				Serial.println("Light On Sent");
	// 			if(ifttt.triggerEvent(LIGHTS_ON_EVENT, ssid, ip.toString()))
	// 			{
	// 				light_status = ON;
	// 				Serial.println("Light On Sent");
	// 			
	// 			} 
	// 			else{
	// 				Serial.println("IFTTT send Failed!");
	// 				}
			}
		}
	
		if(second_cnt)
		{
			second_cnt--;
		}
		else if(light_status == ON)
		{
			led1.off();
			second_cnt = TIMEOUT_S;
			light_status = OFF;
			Serial.println("Light Off Sent");
	// 		second_cnt = TIMEOUT_S;
	// 		if(ifttt.triggerEvent(LIGHTS_OFF_EVENT, ssid, ip.toString()))
	// 		{
	// 			light_status = OFF;
	// 			Serial.println("Light On Sent");
	// 		}
	// 		else{
	// 			Serial.println("IFTTT send Failed!");
	// 		}
		}
	}
	
	Blynk.run();
	delay(1000);
  
}
