#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "38c13c9fa3aa40578e1caf0abba956a9";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MiPhone";
char pass[] = "kaskus1234";


bool switches = false; // false = relay mati (HIGH) , true = relay nyala (LOW)
int SensorValue = 0;


const int GasPin = A0;

WidgetBridge bridge1(V1);

// Timer for blynking
BlynkTimer timer;

BLYNK_READ(V1)
{
  // This command writes Arduino's uptime in seconds to Virtual Pin (5)
  
}

void setup()
{

  
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
// Call blynkAnotherDevice every second
  timer.setInterval(1000L, blynkAnotherDevice);

}

void loop()
{
  Blynk.run();
   SensorValue=analogRead(A0);
   Serial.println(SensorValue);
   if


    timer.run();
}

void blynkAnotherDevice() // Here we will send HIGH or LOW once per second
{
  // Send value to another device
//  if(touched == true){
//    bridge1.digitalWrite(V1, HIGH);  
//      bridge1.virtualWrite(V1,1);
//    }else if(touched == false){
//      bridge1.digitalWrite(V1, LOW);  
//      bridge1.virtualWrite(V1,0);
//      }   


  
   if(SensorValue < 100){ // kalo gas tnggi maka nyalakan
      Serial.println(SensorValue);
      bridge1.digitalWrite(V1, HIGH);  // maka nyalakan
      bridge1.virtualWrite(V1,1);
    }else if(SensorValue > 100){ // kalo lampu Mati
      bridge1.digitalWrite(V1, LOW);  //  maka nyalakan
      bridge1.virtualWrite(V1,0);
      }   
  
 
}
BLYNK_CONNECTED() {
  bridge1.setAuthToken("20ba5cb6dd8e4f0f8d1aeea4caca1b15"); 
  // Place the AuthToken of the second hardware here
