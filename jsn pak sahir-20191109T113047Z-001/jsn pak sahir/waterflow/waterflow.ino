 byte indikator = 13;
 
byte sensorInt = 0; 
byte flowsensor = 14;
 
float konstanta = 4.5; //konstanta flow meter
 
volatile byte pulseCount;
 
float debit;
unsigned int flowmlt;
unsigned long totalmlt;
 
unsigned long oldTime;
 
void setup()
{
 
// Inisialisasi port serial
Serial.begin(9600);
 
pinMode(indikator, OUTPUT);
digitalWrite(indikator, HIGH); 
 
pinMode(flowsensor, INPUT);
digitalWrite(flowsensor, HIGH);
 
pulseCount = 0;
debit = 0.0;
flowmlt = 0;
totalmlt = 0;
oldTime = 0;
 
attachInterrupt(sensorInt, pulseCounter, FALLING);
}
 
 
void loop()
{
 
if((millis() - oldTime) > 1000) 
{ 
detachInterrupt(sensorInt);
debit = ((1000.0 / (millis() - oldTime)) * pulseCount) / konstanta;
oldTime = millis();
flowmlt = (debit / 60) * 1000;
totalmlt += flowmlt;
 
unsigned int frac;
 
Serial.print("Debit air: ");
Serial.print(int(debit));
Serial.print("L/min");
Serial.print("\t");
 
Serial.print("Volume: "); 
Serial.print(totalmlt);
Serial.println("mL"); 
 
pulseCount = 0;
 
attachInterrupt(sensorInt, pulseCounter, FALLING);
}
}
 
 
void pulseCounter()
{
// Increment the pulse counter
pulseCount++;
}
