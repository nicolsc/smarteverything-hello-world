#include <Arduino.h>
#include <Wire.h>
#define DELAY 600000

void setup() {
  SerialUSB.begin(115200);

  SigFox.begin(19200);
  initSigfox();
  blink();
}

void loop() {
  resetLEDs();
  ledBlueLight(HIGH);
  // put your main code here, to run repeatedly:
  bool success;
  success = sendSigfox("CAFE");
  ledBlueLight(LOW);
  if (success){
    ledGreenLight(HIGH);
  }
  else{
    ledRedLight(HIGH);
  }
  delay(DELAY);
}
void initSigfox(){
  SigFox.print("+++");
  while (!SigFox.available()){
    delay(100);
  }
  while (SigFox.available()){
    SerialUSB.print(SigFox.read());
  }
  SerialUSB.println("\n ** Setup OK **");
}
bool sendSigfox(String frame){
  String status = "";
  char output;
  SerialUSB.print("AT$SF=");
  SerialUSB.println(frame);
  SigFox.print("AT$SF=");
  SigFox.print(frame);
  SigFox.print("\r");
  while (!SigFox.available());
  
  while(SigFox.available()){
    output = (char)SigFox.read();
    status += output;
    SerialUSB.println(output);
    delay(10);
  }
  SerialUSB.print("Status \t");
  SerialUSB.println(status);
     if (status == "OK\r"){
      //Success :)
      return true;
    }
    else{
      return false;
    }
  delay(DELAY);
}
void resetLEDs(){
  ledRedLight(LOW);
  ledGreenLight(LOW);
  ledBlueLight(LOW);
}
void blink(){
  ledRedLight(HIGH);
  delay(500);
  ledRedLight(LOW);
  delay(500);
  ledGreenLight(HIGH);
  delay(500);
}
