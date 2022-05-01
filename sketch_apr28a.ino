#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int LED_R = 9;
int Resister = A0;



void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  pinMode(LED_R, OUTPUT);

}

void loop() {
  int val = analogRead(A0) / 4;
  analogWrite(LED_R, val);

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("val : ");
  lcd.print(val);
  delay(100);
}
