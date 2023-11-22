#include <IRremote.h>

#define frForward 6 // FR forw
#define flForward 11 // FL forw 
#define brForward 2 // BR forw
#define blForward 4 // BL forw

#define frBackward 13 // FR backw
#define flBackward 12 // FL backw
#define brBackward 3 // BR backw
#define blBackward 5 // BL backw

#define IRPinData 8
#define IRPinGND 9
#define IRPinVCC 10

void stopAll(){
  for(int pin = 2; pin<8; pin++){
    digitalWrite(pin,LOW);
  }
  digitalWrite(11,LOW);
   digitalWrite(12,LOW);
   digitalWrite(13,LOW);
}

void turnRight(int time){
  if(time == 0){
    time = 1000;
  }
  analogWrite(blForward, 150);
  analogWrite(frBackward, 150);

  analogWrite(flForward, 150);
  analogWrite(brBackward, 150);

  delay(time);
  stopAll();
}

void turnLeft(int time){
  if(time == 0){
    time = 1000;
  }
  analogWrite(blBackward, 150);
  analogWrite(frForward, 150);

  analogWrite(flBackward, 150);
  analogWrite(brForward, 150);

  delay(time);
  stopAll();
}

void goForward(int time){
  if(time == 0){
    time = 1000;
  }
  analogWrite(blForward, 150);
  analogWrite(frForward, 150);

  analogWrite(flForward, 150);
  analogWrite(brForward, 150);

  delay(time);
  stopAll();
}

void goBackward(int time){
  if(time == 0){
    time = 1000;
  }
  analogWrite(blBackward, 150);
  analogWrite(frBackward, 150);

  analogWrite(flBackward, 150);
  analogWrite(brBackward, 150);

  delay(time);
  stopAll();
}

void setup() {
  // put your setup code here, to run once:
  IrReceiver.begin(IRPinData);
  pinMode(frForward, OUTPUT);
  pinMode(flForward, OUTPUT);
  pinMode(blForward, OUTPUT);
  pinMode(brForward, OUTPUT);
  pinMode(frBackward, OUTPUT);
  pinMode(flBackward, OUTPUT);
  pinMode(blBackward, OUTPUT);
  pinMode(brBackward, OUTPUT);
  
  pinMode(IRPinVCC, OUTPUT);
  pinMode(IRPinGND, OUTPUT);
  digitalWrite(IRPinVCC, HIGH);
  digitalWrite(IRPinGND, LOW);
  Serial.begin(9600);
  analogWrite(frBackward, 150);
  delay(1000);
  //turnLeft(0);
  
  
  stopAll();

}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    
    uint16_t command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    switch(command){
      case 9:
        goForward(250);
        break;
      case 10:
        turnLeft(250);
        break;
      case 8:
        turnRight(250);
        break;
      case 1:
        goBackward(250);
        break;
    }
  }
}
