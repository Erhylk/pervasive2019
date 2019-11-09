#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
//#include <ESP8266HTTPClient.h>
BlynkTimer timer;

String apiKey = "3KIQULAL6KKXFX1N";     //  Enter your Write API key from ThingSpeak
const char *ssid =  "sjsj";     // replace with your wifi ssid 
const char *pass =  "mnbvcxza"; // wpa2 key
const char* server = "api.thingspeak.com"; //host Thingspeak
char auth[] = "QkZgLXRlaP8p9DgvNghGWEM81SvgbOLH"; // Token From Email Blynk


WiFiClient client;

void setup()
{
      Blynk.begin(auth, ssid, pass);
       Serial.begin(115200);
       delay(10);

       Serial.println("Connecting to ");
       Serial.println(ssid);


       WiFi.begin(ssid, pass);

      while (WiFi.status() != WL_CONNECTED)
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");

}

void loop()
{

    float sensorVoltage;
    float sensorValue;

    Blynk.run();
    timer.run();
    
  sensorValue = analogRead(A0); // membaca tengan dari sensor dalam bentuk integer
  sensorVoltage = sensorValue/1024*5.0;

  if (sensorVoltage >= 2.0) {
    Blynk.notify("GAUGE DETECTION");
  }
     
              if (isnan(sensorVoltage))
                 {
                     Serial.println("Failed to read from Water Level sensor!");
                      return;
                 }
                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      { 
                           
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(sensorVoltage);
                             postStr += "\r\n\r\n";

                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);

                              Serial.print("sensor voltage = ");
                              Serial.print(sensorVoltage);
//                            Serial.println(" V");
                              delay(1000);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();

          Serial.println("Waiting...");
 
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(10000);
}
