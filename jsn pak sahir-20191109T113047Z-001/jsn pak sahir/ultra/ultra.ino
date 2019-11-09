int trig= 2;            // D4//orange
int echo= 0;            //D3//merah
long durasi, jarak;     // membuat variabel durasi dan jarak

void setup() {
pinMode(trig, OUTPUT);    // set pin trig menjadi OUTPUT
pinMode(echo, INPUT);     // set pin echo menjadi INPUT
Serial.begin(9600);       // digunakan untuk komunikasi Serial dengan komputer
}

void loop() {

// program dibawah ini agar trigger memancarakan suara ultrasonic
digitalWrite(trig, LOW);
delayMicroseconds(8);
digitalWrite(trig, HIGH);
delayMicroseconds(8);
digitalWrite(trig, LOW);
delayMicroseconds(8);

durasi= pulseIn(echo, HIGH);  // menerima suara ultrasonic
jarak= (durasi/2) / 29.1;     // mengubah durasi menjadi jarak (cm)
Serial.println(jarak);        // menampilkan jarak pada Serial Monitor
delay (1500);

}
