#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

#define TRIG_PIN 2
#define ECHO_PIN 3
#define DISPLAY_COLS 16

LiquidCrystal_I2C lcd(0x27, DISPLAY_COLS, 2);

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;

  int barLength = map(distance, 0, 50, 0, DISPLAY_COLS);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  lcd.setCursor(0, 1);
  for (int i = 0; i < barLength; i++) {
    lcd.print("#");
  }

  delay(100);
}
