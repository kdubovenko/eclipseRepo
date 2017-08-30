#define BLYNK_PRINT Serial

#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include "IFTTTMaker.h"
#include <BlynkSimpleEsp8266.h>
#include "TimeLib.h"
//#include "WidgetRTC.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <IRremoteESP8266.h>
//#include <IRrecv.h>
#include <IRutils.h>
#include <IRsend.h>
#include <DHT.h>

#define LED_PIN 16


#define BUF_SIZE      200
#define MIN_BUF_SIZE  60

char ssid[] = "KonstaCat"; //  your network SSID (name) 
char pass[] = "0223#tpa";   // your network password

//Thingspeak stuff

#define KEY "cK9gQ8qgo_F1f1SHy3iCP"  // Get it from this page https://ifttt.com/services/maker/settings
#define LIGHTS_ON_EVENT "lifx_light_on" // Name of your event name, set when you are creating the applet
#define LIGHTS_OFF_EVENT "lifx_light_off" // Name of your event name, set when you are creating the applet

//Blynk stuff

char auth[] = "66b347d0823b4121b310ed404b509790";
WidgetLED led1(V1);
WidgetLED led2(V5);
//WidgetRTC rtc;

//time stuff
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

//WiFiClient  client;
WiFiClientSecure client;
IFTTTMaker ifttt(KEY, client);

//IR Remote
IRsend irsend(4);
//IRrecv irrecv(5);
//decode_results results;

//temperature / humidity sensor
#define DHTPIN 0          // What digital pin we're connected to (D3)

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11     // DHT 11
#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);


//custom automation stuff
#define ON  1
#define OFF 0
#define TIMEOUT_S 300 //5 min
#define UTC_OFFSET  (-7)
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
//unsigned long myChannelNumber = 286926;
//const char * myWriteAPIKey = "F1VW3ERE39QPBZN7";
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

BLYNK_WRITE(V0)
{
  int tempval;
  tempval = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  digitalWrite(LED_PIN, !tempval);

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

BLYNK_WRITE(V9)
{
  int tempval;
  tempval = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  if(tempval == 1)
  {
    irsend.sendNEC(0x5EA158A7, 32);
  }
  else if(tempval == -1)
  {
    irsend.sendNEC(0x5EA1D827, 32);
  }
  //Serial.println(tempval);
  
}

BLYNK_WRITE(V11)
{
  int tempval;
  tempval = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  if(tempval)
  {
    //Serial.println("Sending Reciever p-on NEC");
    irsend.sendNEC(0x5EA1B847, 32);
  }
}
BLYNK_WRITE(V12)
{
  int tempval;
  tempval = param.asInt(); //assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  if(tempval)
  {
    //Serial.println("Sending Reciever p-off NEC");
    irsend.sendNEC(0x5EA17887, 32);
  }
}

unsigned long millis_track = 0;

void setup() {

  Serial.begin(115200);
//  WiFi.begin(ssid, pass);
//   ThingSpeak.begin(client);
  pinMode(5, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  millis_track = millis();
  
  //Blynk.begin(auth, ssid, pass);
  Blynk.begin(auth, ssid, pass, IPAddress(10,0,0,21), 8442);
  Blynk.virtualWrite(V2, TimeoutValue);

  //irrecv.enableIRIn();  // Start the receiver
  irsend.begin();    // Start the transmitter
  
  setTime(getTime());
  
  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  String currentDate = String(day()) + "/" + month() + "/" + year();
  Serial.print("Current time: ");
  Serial.print(currentTime);
  Serial.print(" ");
  Serial.print(currentDate);
  Serial.println();
  
//  WiFi.mode(WIFI_STA);
//  WiFi.disconnect();
//  delay(100);
// 
//  // Attempt to connect to Wifi network:
//  Serial.print("Connecting Wifi: ");
//  Serial.println(ssid);
//  WiFi.begin(ssid, pass);
//  while (WiFi.status() != WL_CONNECTED) {
//    Serial.print(".");
//    delay(500);
//  }
//  Serial.println("");
//  Serial.println("WiFi connected");
//  Serial.println("IP address: ");
  ip = WiFi.localIP();
  Serial.println(ip);
  
  Serial.println("Huzzah motion detect started");
  

}

void loop() 
{  
  if((millis() - millis_track) >= 1000)
  {
    millis_track = millis();
    one_second_loop();
  }
  Blynk.run();
}

void one_second_loop()
{
  bool motion_det;
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  //Blynk.syncAll();
  Blynk.syncVirtual(V0);
  
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
    }
  }

  if (isnan(h) || isnan(t)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  else
  {
    // You can send any value at any time.
    // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V13, h);
    Blynk.virtualWrite(V10, t);
  }
}




