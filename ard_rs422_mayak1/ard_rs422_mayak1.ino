#include <SoftwareSerial.h>

#define SSerialRX        10
#define SSerialTX        11 
 
SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX

const int ledPin =  12;     // TX
const int ledPin2 =  9;     // RX
int lectura = 200;

void sendCommand(){
  byte buf[12];  
  for(byte i = 0; i < 12; i++) {
    buf[i] = 0;
  }
  buf[0] = 85;
  buf[1] = 20;
  buf[2] = 21;
  buf[3] = 22;
  buf[4] = 23;
  buf[5] = 24;
  buf[6] = 25;
  buf[7] = 26;
  buf[8] = 27;
  buf[9] = 28;

  
  int checkSum = 0;
  for(byte i = 0; i < 10; i++) {
    checkSum+= buf[i];
  }
  
  buf[10] = lowByte(checkSum);
  buf[11] = 170; 
  
  for(byte i=0;i<(12);i++){
    RS485Serial.write(buf[i]);
  } 
}

void setup() { 
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);
  RS485Serial.begin(9600);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin, LOW);
} 
 
void loop(){
  digitalWrite(ledPin, HIGH);
  delay(1000);
  sendCommand();
  digitalWrite(ledPin, LOW);
}
