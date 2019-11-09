const int pinBuzzer = 13;
//#define tone;

void setup() {
pinMode(pinBuzzer, OUTPUT);
}

void loop() {
//nada pendek
digitalWrite(pinBuzzer, HIGH);
delay(200);
digitalWrite(pinBuzzer, LOW);
delay(200);

//nada panjang
digitalWrite(pinBuzzer, HIGH);
delay(1000);
digitalWrite(pinBuzzer, LOW);
delay(1000);
}

//void loop() {
//  // matikan LED
//  digitalWrite( 13, LOW );
//  // mainkan nada di pin#8 dg. frekuensi 261Hz selama 500 ms
//  tone( 8, 261 );
//  delay( 500 );
//  // nyalakan LED
//  digitalWrite( 13, HIGH );
//  // mainkan nada di pin#8 dg. frekuensi 392Hz selama 500 ms
//  tone( 8, 392 );
//  delay( 500 );
//}
