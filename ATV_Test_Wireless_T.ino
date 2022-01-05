#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define led 12
int xVar=0;
int yVar =1;
int potValX;
int angleValue;
int onOff;
int potValY;
RF24 radio(9, 8); // CE, CSN make radio
const byte add[6] ="00001";//addresses for pipe - like code
void setup() {
  pinMode(xVar, INPUT);
  pinMode(yVar, INPUT);
  radio.begin();
  radio.openWritingPipe(add); 
  radio.setPALevel(RF24_PA_MIN);
  Serial.begin(9600);
  radio.stopListening();
}
void loop() {
 
 
   potValX = analogRead(xVar);
   potValY=analogRead(yVar);
//    Serial.print("potX ");
//    Serial.print(potValX);
//     Serial.println("potY ");
//     Serial.print(potValY);
   angleValue = map(potValY, 0, 1023, 65,90 );

   onOff=0;
  if(potValX>=700){
    onOff=-1;
  }else if(potValX<=400){
    onOff=1;
  }else{
    onOff=0;
  }

int  arr[2] = {angleValue,onOff};
    Serial.print("onOff");
       Serial.print(arr[1]);
          Serial.print(" ");
  Serial.print("angleV");
       Serial.print(arr[0]);
       Serial.print(" ");
  radio.write(&arr, sizeof(arr));
//  delay(5);
//  radio.startListening();
//  while (!radio.available());
//  radio.read(&buttonState, sizeof(buttonState));
//  if (buttonState == HIGH) {
//    digitalWrite(led, HIGH);
//  }
//  else {
//    digitalWrite(led, LOW);
//  }
}
