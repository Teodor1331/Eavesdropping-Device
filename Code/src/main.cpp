#include <Arduino.h>
#include <SoftwareSerial.h>

#define analogPin A1
#define pinArduinoRX 2
#define pinArduinoTX 3

SoftwareSerial mySerial(pinArduinoRX, pinArduinoTX);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  int readValue = analogRead(analogPin);
  float voltage = readValue * 5.0 / 1024.0;
  mySerial.println(voltage);

  delay(20);
}