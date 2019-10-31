#include <ESP8266WiFi.h>

String apiKey = "3KIQULAL6KKXFX1N";     //  Enter your Write API key from ThingSpeak
const char *ssid =  "sjsj";     // replace with your wifi ssid and wpa2 key
const char *pass =  "mnbvcxza";
const char* server = "api.thingspeak.com";



WiFiClient client;

void setup()
{
       Serial.begin(115200);
       delay(10);
//       dht.begin();

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
    
  sensorValue = analogRead(A0); // membaca tengan dari sensor dalam bentuk integer
  sensorVoltage = sensorValue/1024*5.0;
     
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
//                             postStr +="&field2=";
//                             postStr += String(h);
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

//                            Serial.print("Sensor Value = ");
//                            Serial.println(sensorValue);
//                            Serial.print("Sensor Voltage = ");
//                            Serial.println(sensorVoltage);
//                            Serial.print("Tinggi Air = ");
//                            Serial.println(tinggiAir);
//                            Serial.println();
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
