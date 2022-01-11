
#include<LiquidCrystal.h>
int Contrast=150;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int PIRpin = 13; 

int PIRState = 0; 

int gled = 8;
int rled = 10;

void setup() {
 Serial.begin(9600);
 pinMode(PIRpin, INPUT);
 pinMode(gled, OUTPUT);
 pinMode(rled, OUTPUT);

analogWrite(6,Contrast);
lcd.begin(16, 2);
}

void loop() {
 int PIRState = digitalRead(PIRpin); 
 Serial.println(PIRState); 
 delay(1); 
lcd.setCursor(0, 0);
if (PIRState == HIGH)
{
 lcd.print("Motion    ");
 digitalWrite(gled, HIGH); 
 digitalWrite(rled, LOW); 
}
else{
  lcd.print("No Motion");
  digitalWrite(gled, LOW);
  digitalWrite(rled, HIGH); 
}


}
