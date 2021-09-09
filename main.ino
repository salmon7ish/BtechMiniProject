#include <SoftwareSerial.h>
#include<String.h>
#define pin 8

SoftwareSerial esp8266(2, 3);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Started");

  // set the data rate for the SoftwareSerial port
  esp8266.begin(115200);
  delay(2000);
  esp8266.println("AT");
     fun();
  esp8266.println("AT+RST");
   // fun();
   delay(2000);
  esp8266.println("AT+CWJAP=\"hello\",\"praful123\"");
  delay(2000);
    fun();
  esp8266.println("AT+CWMODE=1");
    fun();
}

void loop() {
 static int previous_value=1;
 int new_value;
 String Status;
 char str[]="AT+CIPSTART=\"TCP\",\"www.notifymyandroid.com\",80";
 new_value = digitalRead(pin);
 delay(1000);

 if(new_value!=previous_value)
 {
  esp8266.println("AT+CIPSTART=\"TCP\",\"www.notifymyandroid.com\",80");
  fun();
  previous_value=new_value;
  delay(1000);
  if(new_value==0)
  {
    Status = "OPEN";
    Serial.println("OPEN");
  }
  else
  {
    Status = "CLOSE";
    Serial.println("CLOSE");
  }
  String getstr = String("GET https://www.notifymyandroid.com/publicapi/notify?apikey=c0613817e16d72f07b55574a70bbe011ec228b5883f94e6a&application=ESP&event="+Status+"&description=jv\r\n\r\n");
  int len=getstr.length();
  String cmd = "AT+CIPSEND=";
  cmd += String(getstr.length());
  esp8266.println(cmd);
  delay(500);
  fun();
  }
  delay(1000);
}

void fun(){
  delay(100);
  while (esp8266.available()){
     String inData = esp8266.readStringUntil('\n');
     Serial.println("Got reponse from ESP8266: " + inData);
}
}
