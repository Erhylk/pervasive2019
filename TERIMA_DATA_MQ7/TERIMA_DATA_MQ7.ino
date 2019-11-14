#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

const int pinBuzzer = 13;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "MxmqnosD1sLAHj6jjgud5wtDy81ldtV4";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "sjsj";
char pass[] = "mnbvcxza";

bool touched = false;

void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(13,OUTPUT);
  digitalWrite(13,00);

  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  buzzer(pinValue);
  // process received value
}

void buzzer(int pinValue){
  if(pinValue == 0){
    digitalWrite(pinBuzzer,1);
  }
  else if(pinValue == 1){
    digitalWrite(pinBuzzer,00);
  }
  Serial.print(pinValue);
}
