#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "363a0940b4564ef0b123629937006257";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "JARINGAN";
char pass[] = "SENSORNIR";

bool touched = false;

void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(2,OUTPUT);
  digitalWrite(2,00);

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
    digitalWrite(2,1);
    Blynk.notify("LAMPU MATI");
//     digitalWrite(2,HIGH);
    }//NYALA
  else if(pinValue == 0){
    digitalWrite(2,00);
    Blynk.notify("LAMPU MENYALA");
//     digitalWrite(2,LOW);
    }//MATI
}
