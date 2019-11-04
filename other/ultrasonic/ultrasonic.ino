#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
//WiFi Details//
char ssid[] = "FirahWiFi";
char pass[] = "1234";


const int trigPin = 2;  //D4
const int echoPin = 0;  //D

// defines variables
long duration;
int distance;

WiFiClient client;

unsigned long myChannelField = 898930; // Channel ID
const int ChannelField = 1; // Which channel to write data
const char * myWriteAPIKey = "LV4ZQQQ9KL9TQ2YM"; // Your write API Key

void setup()
{
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(115200); // Starts the serial communication
WiFi.mode(WIFI_STA);
ThingSpeak.begin(client);
}

void loop()
{

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(2000);
}
