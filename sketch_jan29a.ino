//INCLUDED LIBRARIES
#include "GPRS_Shield_Arduino.h"
#include <SoftwareSerial.h>
#include <Wire.h>
//SERIAL PIN ASSIGNMENT, BAUDRATE, PHONE NUMBER, MESSAGE
#define PIN_TX    3
#define PIN_RX    2
#define BAUDRATE  9600

#define MESSAGE_LENGTH 160


char PHONE_NUMBER[]= "09551939959";
char MESSAGE[] =   "Read,Waiting...";
char qMESSAGE[] =   "A text message will be sent when your files are ready.";
char message[MESSAGE_LENGTH];
int messageIndex = 0;
char phone[16];
char datetime[24];

GPRS GSMTEST(PIN_RX,PIN_TX,BAUDRATE);//RX,TX,BAUDRATE

void setup() {
  Serial.begin(9600);

    while(!GSMTEST.init()) {
      delay(1000);
      //digitalWrite(7,LOW);
      Serial.print("INIT ERROR\r\n");
  } 
  Serial.print("read");
  GSMTEST.sendSMS(PHONE_NUMBER,MESSAGE); //DEFINE PHONE NUMBER AND TEXT
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
while(!Serial.available());

String phonenumber = Serial.readString();
Serial.println("data received!");

char mybuffer[sizeof(phonenumber)];
phonenumber.toCharArray(mybuffer,sizeof(mybuffer));
Serial.print(phonenumber);
//GSMTEST.sendSMS(PHONE_NUMBER,qMESSAGE); //DEFINE PHONE NUMBER AND TEXT

}
