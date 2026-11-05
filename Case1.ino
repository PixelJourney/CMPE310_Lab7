
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
float R1 = 330.0;
float R2 = 330.0;
float iVoltage = 5.0;

int voltageV = A0;

void setup() {
    pinMode(voltageV, INPUT);
    lcd.init();
    lcd.clear();
    lcd.backlight();
}

void loop() {
    int voltageMeasure = analogRead(voltageV);
    float Vcalc = iVoltage * (R1 / (R1 + R2));
    float Vmeasure = (iVoltage / 1023.0) * voltageMeasure;

    lcd.setCursor(0, 0);
    lcd.print("Calculated: ");
    lcd.print(Vcalc);

    lcd.setCursor(0, 1);
    lcd.print("Measured: ");
    lcd.print(Vmeasure);
}
