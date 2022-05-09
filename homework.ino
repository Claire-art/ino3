#include <LiquidCrystal_I2C.h>
#include <Wire.h>
int right;

int tact_blue = 13;
  int tact_red = 2;

  int led[] = {5,6,7};
  int count = 0;


LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {

  for (int i=0; i<3;i++){
    pinMode(led[i], OUTPUT);
    }

    pinMode(tact_blue, INPUT_PULLUP);
    pinMode(tact_red, INPUT_PULLUP);

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
}

void loop() {
  int val = analogRead(A0) /4;
  analogWrite(led[right],val);

  lcd.clear();
  lcd.setCursor(0,0);
  
  if (led[right]==5) {lcd.print("White");}
  if (led[right]==6) {lcd.print("Yellow");}
  if (led[right]==7){lcd.print("Red");}
  
  lcd.print(val);
  delay(100);
 
  
  
  if(count < 0 || count > 2){
    int a = (count <0) ? 2 : 0;
    count = a;
    showLight (count);
  }
  if (digitalRead(tact_blue) == LOW){
    count ++;
    showLight(count);
  }
  else if (digitalRead(tact_red)==LOW){
    count --;
    showLight(count);
  }

  delay(250);

  


}

void showLight(int a){
  for (int i=0; i<3; i=i+1){
    if (a==i) {digitalWrite(led[i], HIGH); right=a;}
    else digitalWrite(led[i], LOW);
  }
 }
