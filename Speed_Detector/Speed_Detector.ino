#include<LiquidCrystal.h>
int Contrast=150;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int val;
int val2;
int led = 10;
int led2 = 13;
int timer;
int timer2;
float TIME;
float distance = 0.24;
float speedX;
int constant;
int constant2;
void setup() {
Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(led2, OUTPUT);
analogWrite(6,Contrast);
lcd.begin(16, 2);
}
void loop() {
  delay(99);
val = analogRead(A0);
//Serial.println(val);
val2 = analogRead(A1);
Serial.println(val2);

if (val>10)
{
digitalWrite(led, LOW);
}
else{
digitalWrite(led, HIGH);

}

if (val2>10)
{
digitalWrite(led2, LOW);
}
else{
digitalWrite(led2, HIGH);
}
if(digitalRead(led) == HIGH){
  timer = millis();
  constant = 1;
}
if(digitalRead(led2)== HIGH){
  timer2 = millis();
  constant2 = 1;
}
if (constant == 1 && constant2 ==1){
  if(timer>timer2){
    TIME = timer - timer2 ;
  }
  else
  {
    TIME = timer2 - timer;
  }
 TIME = TIME/1000;
 speedX=(distance/TIME);
 speedX = speedX*3600;
 speedX=speedX/1000;
 lcd.setCursor(0, 0);
 lcd.print("Speed:");
 lcd.setCursor(0, 1);
 lcd.print(speedX, 1);
 lcd.print(" Km/Hr ");
}

}
