#include "Arduino.h"
#include "SPI.h"
//The setup function is called once at startup of the sketch

#define SPI_INTERVAL_MS	5

SPIClass PatchSPI;
unsigned long millis_track;
bool SPI_read_enabled = false;

void setup()
{
	Serial.begin(115200);
	Serial.println("Starting SPI COM");

	PatchSPI.begin();
	PatchSPI.beginTransaction(SPISettings(4000000,MSBFIRST,SPI_MODE0));

	millis_track = millis();

	Serial.println("Serial COM started");
	Serial.println("Type E to start reading data from Patch");
	Serial.println("Type 0 to stop reading data Patch");

}

// The loop function is called in an endless loop
void loop()
{
	char input;
	uint16_t SPI_data;
	static long cnt = 0;

	if (Serial.available())
	{
		input = Serial.read();
		Serial.write(input);
		if((input == 'E') || (input == 'e'))
		{
			Serial.println();
			Serial.println("Starting Patch Read");
			SPI_read_enabled = true;
			PatchSPI.transfer16(0x0045); //send start command to the patch
		}
		else if(input == '0')
		{
			cnt = 0;
			Serial.println();
			Serial.println("Stopping Patch Read");
			SPI_read_enabled = false;
			PatchSPI.transfer16(0xFFFF); //
		}
	}
	if((millis() - millis_track) >= SPI_INTERVAL_MS)
	{
		if(SPI_read_enabled == true)
		{
			millis_track = millis();
			SPI_data = PatchSPI.transfer16(0); //read available data from the patch
			Serial.print(cnt);
			Serial.print(", ");
			Serial.println(SPI_data);
			cnt++;
		}
	}
}
