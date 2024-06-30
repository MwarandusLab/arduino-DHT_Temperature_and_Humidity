#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

#include <dht.h>

#define dataPin 8 // Defines pin number to which the sensor is connected
dht DHT; // Creats a DHT object

LiquidCrystal_I2C lcd_A(0x26, 16, 4);
LiquidCrystal_I2C lcd_B(0x27, 16, 4);

void setup() {
  Serial.begin(9600);

  lcd_A.begin(16, 4);
  lcd_A.backlight();

  lcd_B.begin(16, 4);
  lcd_B.backlight();

  
  lcd_A.clear();
  lcd_A.setCursor(0,1);
  lcd_A.print("SYSTEM");
  lcd_A.setCursor(0,2);
  lcd_A.print("INITIALIZATION")
  
  lcd_B.clear();
  lcd_B.setCursor(0,1);
  lcd_B.print("SYSTEM");
  lcd_B.setCursor(0,2);
  lcd_B.print("INITIALIZATION")

  delay(3000);


}
void loop() {
  int readData = DHT.read22(dataPin); // Reads the data from the sensor
  float t = DHT.temperature; // Gets the values of the temperature
  float h = DHT.humidity; // Gets the values of the humidity
  
  // Printing the results on the serial monitor
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  
  delay(2000); // Delays 2 secods, as the DHT22 sampling rate is 0.5Hz
}