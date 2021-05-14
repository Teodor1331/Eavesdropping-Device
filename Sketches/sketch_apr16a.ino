#include <Arduino.h>
#include <SoftwareSerial.h>

#define analogPin A0
#define pinArduinoRX 8
#define pinArduinoTX 9

SoftwareSerial mySerial(pinArduinoRX, pinArduinoTX);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  int readValue = analogRead(analogPin);
  float voltage = readValue * 5.0 / 1024.0;
  mySerial.println(readValue);
}
