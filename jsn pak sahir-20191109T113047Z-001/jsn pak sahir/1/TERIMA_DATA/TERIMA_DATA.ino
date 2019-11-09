define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "20ba5cb6dd8e4f0f8d1aeea4caca1b15";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MiPhone";
char pass[] = "kaskus1234";

bool touched = false;

void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(D8,OUTPUT);
  digitalWrite(D8,00);

  pinMode(D7,OUTPUT);
  digitalWrite(D7,HIGH);

  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
 
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  AturRelay(pinValue);
  // process received value
}

void AturRelay(int pinValue){
  if(pinValue == 1){
    digitalWrite(D8,1);
     digitalWrite(D7,HIGH);
    }//NYALA
  else if(pinValue == 0){
    digitalWrite(D8,00);
     digitalWrite(D7,LOW);
    }//MATI
}
