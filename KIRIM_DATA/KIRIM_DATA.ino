#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

//DEFINE PINS 
const int trigPin = 2; //D4
const int echoPin = 0; //D3

//DEFINE VARIABLES
long duration, distance;

char auth[] = "8332411289ea46ccae43f96799072c0f";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "JARINGAN";
char pass[] = "SENSORNIR";


bool switches = false; // false = relay mati (HIGH) , true = relay nyala (LOW)

WidgetBridge bridge1(V1);

// Timer for blynking
BlynkTimer timer;

BLYNK_READ(V1)
{
  // This command writes Arduino's uptime in seconds to Virtual Pin (5)
  
}

void setup()
{

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, blynkAnotherDevice);

}

void loop()
{
  Blynk.run();

    timer.run();
}

void blynkAnotherDevice() // Here we will send HIGH or LOW once per second
{ 

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
distance = duration*0.034/2;
Serial.println(distance);

  
   if(distance > 50){ // jika nilai lebih dari 50 maka lampu mati
//      Serial.println(SensorValue);
      bridge1.digitalWrite(V1, HIGH);  // 
      bridge1.virtualWrite(V1,1);
    }else if(distance < 51 ){ // jika nilai lebih dari 50 maka lampu menyala
      bridge1.digitalWrite(V1, LOW); 
      bridge1.virtualWrite(V1,0);
      }   
  
}
BLYNK_CONNECTED() {
  bridge1.setAuthToken("363a0940b4564ef0b123629937006257"); 
  // Place the AuthToken of the second hardware here
}
