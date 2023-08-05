//Bharat_intern_2nd_Task
//Health Monitoring System
//by Subham Pati
#include<OneWire.h>
#include<Wire.h>
#include<DallasTemperature.h>
#include<LiquidCrystal_I2C.h>
const int SENSOR_PIN =13;
OneWire OneWire(SENSOR_PIN);
DallasTemperature sensors(&OneWire);
LiquidCrystal_I2C lcd(0*27,16,2);
double alpha=0.75;
int period=20;
double refresh=0.0;
float tempCelsius;

void setup() {
  pinMode(A0,INPUT);
  sensors.begin();
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
}

void loop() {
 static double oldvalue=0;
 static double oldrefresh=0;
int beat =analogRead(A0);
double value= alpha*oldvalue+(0-alpha)*beat;
int refresh= value-oldvalue;
sensors.requestTemperatures();
tempCelsius =sensors.getTempCByIndex(0);
lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Body:  ");
  lcd.print(tempCelsius);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Heart:  ");
  lcd.print(beat/10);
  oldvalue=value;
  oldrefresh=refresh;
  delay(period*10);
  delay(500);

}
