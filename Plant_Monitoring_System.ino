#include <Blynk.h>

#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int sensorValue;
int chk;
int hum;
int temp;
int sensor_pin = A1;
int output_value;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char auth[] = "jkE_OwvHlmEX2726nXLdPnaA8FLboKjE";
char ssid[] = "FaryLink_5EE4BE";
char pass[] = "";

void setup() {
  Blynk.begin(auth, ssid, pass);
  lcd.begin(16,2);
  Serial.begin(9600);
  delay(1000);
  dht.begin();
  Serial.print("Reading From the Sensor...");
  delay(2000);
}

void loop() {
  Blynk.run();
  output_value = analogRead(sensor_pin);
  output_value = map(output_value,550,0,0,100);
  sensorValue = analogRead(0);
  Serial.print("AirQua=");
  Serial.print(sensorValue, DEC);
  Serial.print(" PPM");
  lcd.setCursor(0,0);
  lcd.print("ArQ=");
  lcd.print(sensorValue,DEC);
  lcd.print(" PPM");
  lcd.println("        ");
  lcd.print("   ");
  if (sensorValue >= 175 PPM){
    Serial.print("Harmful Air Quality Detected");

    Serial.print("Harmful Air Quality Detected");
    lcd.setCursor(0,0);
    lcd.print("Harmful Air Qua.");
  }
  delay(10000);
  Serial.print("Moisture : ");
  Serial.print(output_value);
  Serial.print("%");
  delay(10000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Moisture : ");
  lcd.setCursor(0,1);
  lcd.print(output_value);
  lcd.print("%");
  lcd.print("    ");
  if (output_value >= 50%){
    Serial.print("Bad Soil Quality");
    lcd.setCursor(0,0);
    lcd.print("Bad Soil Quality");  
  }
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print("%");
  lcd.print("         ");
  if (hum >= 60) {
    Serial.print("Too Much Humidity");
    lcd.setCursor(0,0);
    lcd.print("Too Much Humidity");
  }
  delay(10000);
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" Celsius");
  lcd.print("    ");
  lcd.print("  ");
  if (temp >= 40) {
    Serial.print("High Temperature");
    lcd.setCursor(0,0);
    lcd.print("High Temperature"); 
  }
  delay(10000);
  delay(2000);
}
