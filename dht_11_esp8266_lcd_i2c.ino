

#include <ESP8266WiFi.h>
#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>



#define DHTPIN 3          
#define DHTTYPE DHT11
//#define DHTTYPE DHT22     

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  dht.begin();
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(11, 0);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("Humi:");
  lcd.setCursor(11, 1);
  lcd.print("%"); 
}

void loop()
{
  Sensor();
}

void Sensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  lcd.setCursor(5, 0);
  lcd.print(t);
  lcd.setCursor(5, 1);
  lcd.print(h);
  delay(1000);
}
