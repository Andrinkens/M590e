#include <SoftwareSerial.h>
SoftwareSerial sSerial(2, 3);

String getDataFromSwrSerial();

void setup() {
  Serial.begin(9600);
  delay(3000);
  Serial.println("Ready to check!");
  Serial.println("Send 'CHECK' to start...");
}

void loop() {
  
  if (Serial.available())
  {
    char ch = ' ';
    String str = "";
    
    while(Serial.available()) 
    {  
       ch = Serial.read();
       str += char(ch); //собираем принятые символы в строку
       delay(3);
    }

    if(str.indexOf("CHECK") > -1)
    {
        Serial.println("Checking 9600 baud...");
        sSerial.begin(9600);
        sSerial.println("AT");
        delay(500);
        if (getDataFromSwrSerial().indexOf("OK")>-1){
          Serial.println("M590e speed already equals 9600 baud!");
          goto stop;// да-да!! ТЫ! Именно ТЫ должен написать в комментах что я пложу говнокод!!!
        }
        else
          Serial.println("No answer...");

        Serial.println("Checking 19200 baud...");
        sSerial.begin(19200);
        sSerial.println("AT");
        delay(500);
        if (getDataFromSwrSerial().indexOf("OK")>-1){
          Serial.println("M590e speed equals 19200 baud!");
          Serial.println("Set new speed = 9600 baud...");
          sSerial.println("AT+IPR=9600");
          delay(1000);
          if (getDataFromSwrSerial().indexOf("OK")>-1)
            Serial.println("OK!!!");
          else
            Serial.println("ERROR!!!");
          goto stop;// да-да!! ТЫ! Именно ТЫ должен написать в комментах что я пложу говнокод!!!
        }
        else
          Serial.println("No answer...");

        Serial.println("Checking 38400 baud...");
        sSerial.begin(38400);
        sSerial.println("AT");
        delay(500);
        if (getDataFromSwrSerial().indexOf("OK")>-1){
          Serial.println("M590e speed equals 38400 baud!");
          Serial.println("Set new speed = 9600 baud...");
          sSerial.println("AT+IPR=9600");
          delay(1000);
          if (getDataFromSwrSerial().indexOf("OK")>-1)
            Serial.println("OK!!!");
          else
            Serial.println("ERROR!!!");
          goto stop;// да-да!! ТЫ! Именно ТЫ должен написать в комментах что я пложу говнокод!!!
        }
        else
          Serial.println("No answer...");

        Serial.println("Checking 57600 baud...");
        sSerial.begin(57600);
        sSerial.println("AT");
        delay(500);
        if (getDataFromSwrSerial().indexOf("OK")>-1){
          Serial.println("M590e speed equals 57600 baud!");
          Serial.println("Set new speed = 9600 baud...");
          sSerial.println("AT+IPR=9600");
          delay(1000);
          if (getDataFromSwrSerial().indexOf("OK")>-1)
            Serial.println("OK!!!");
          else
            Serial.println("ERROR!!!");
          goto stop;// да-да!! ТЫ! Именно ТЫ должен написать в комментах что я пложу говнокод!!!
        }
        else
          Serial.println("No answer...");


        Serial.println("Checking 115200 baud...");
        sSerial.begin(115200);
        sSerial.println("AT");
        delay(500);
        if (getDataFromSwrSerial().indexOf("OK")>-1){
          Serial.println("M590e speed equals 115200 baud!");
          Serial.println("Set new speed = 9600 baud...");
          sSerial.println("AT+IPR=9600");
          delay(1000);
          if (getDataFromSwrSerial().indexOf("OK")>-1)
            Serial.println("OK!!!");
          else
            Serial.println("ERROR!!!");
          goto stop;// да-да!! ТЫ! Именно ТЫ должен написать в комментах что я пложу говнокод!!!
        }
        else
          Serial.println("No answer...");
          
    }
    Serial.println("No connection with module!!!!");
    stop:
    Serial.println("End");
  }
}

String getDataFromSwrSerial(){
  if (sSerial.available()){
    char ch = ' ';
    String str = "";
    while(sSerial.available()) 
    {  
       ch = sSerial.read();
       str += char(ch); //собираем принятые символы в строку
       delay(3);
    }
    return str;
  }
  return "";
}
