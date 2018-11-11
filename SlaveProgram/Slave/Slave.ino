#include<Wire.h>
char x ;
int RM1 = 7;
int RM2 = 6;
int LM1 = 5;
int LM2 = 4;
void setup() {
 Wire.begin(9);
 Wire.onReceive(receiveEvent);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
}
void receiveEvent(int bytes){
  x = Wire.read();
  }

void loop() {
 if(x == 'Y' ){
  digitalWrite(9,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
  delay(2000);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW); 
if(Serial.available()){
  char choice;
  choice = Serial.read();

    
  if(choice == '1'){
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
  }

  if(choice == '2'){
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
  }

  if(choice == '3'){
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,HIGH);
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,HIGH);
  }

  if(choice == '4'){
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,HIGH);
  }

  if(choice == '5'){
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,HIGH);
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
  }
  }
   
  }else 
  
  if(x == 'N')
  {
   digitalWrite(9,HIGH);
    }
    else 
    
    if(x == 'R'){
      digitalWrite(9,LOW);
      }

}
