#include<LiquidCrystal.h>
int Contrast=150;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//reading variables for analog
int val;
int val2;
int led = 10;
int led2 = 13;
//saving the time between when the program intially started and when the object passed through(state change)
int timer;
int timer2;
//total time apart from max and min
float TIME;
//distance between the photointerrupters
float distance = 0.24;
//speed printed on lcd
float speedX;
// constant indicators when state is changes, ensure accuracy
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
  //delays values read from analog
  delay(99);
  //read state at connection A0
val = analogRead(A0);
//Serial.println(val);
  //read state at connection A1
val2 = analogRead(A1);
Serial.println(val2);
//if object passed first photointerrupter, visual indication
if (val>10)
{
digitalWrite(led, LOW);
}
else{
digitalWrite(led, HIGH);

}
//if object passed second photointerrupter, visual indication
if (val2>10)
{
digitalWrite(led2, LOW);
}
else{
digitalWrite(led2, HIGH);
}
  //object detected through first interrupter  -> check and declare timing -> constant changes state
if(digitalRead(led) == HIGH){
  timer = millis();
  constant = 1;
}
   //object detected through second interrupter  -> check and declare timing -> constant2 changes state
if(digitalRead(led2)== HIGH){
  timer2 = millis();
  constant2 = 1;
}
  //object passed both photointerrupters then calculate total TIME
if (constant == 1 && constant2 ==1){
  if(timer>timer2){
    TIME = timer - timer2 ;
  }
  else
  {
    TIME = timer2 - timer;
  }
  // Speed Calculation

 TIME = TIME/1000;
 speedX=(distance/TIME); //speed = distance/time
 speedX = speedX*3600;
 speedX=speedX/1000;
  //position speed on lcd
 lcd.setCursor(0, 0);
 lcd.print("Speed:");
 lcd.setCursor(0, 1);
 lcd.print(speedX, 1);
 lcd.print(" Km/Hr "); //displaying units
}

}
