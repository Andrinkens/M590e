#include <SoftwareSerial.h>
 
SoftwareSerial sSerial(2, 3);//D2 к ноге TXD модуля, а D3 к ноге RXD модуля

void setup() {
  Serial.begin(9600);//Скорость связи с компом
  sSerial.begin(9600);//Скорость связи с M590e
}

void loop() {
  if (sSerial.available())
    Serial.write(sSerial.read());
  if (Serial.available())
    sSerial.write(Serial.read());
}
