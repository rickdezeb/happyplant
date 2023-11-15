#include <Arduino.h>

const int PUMP_PIN = 5;
const int lightSensorPin = A2;
const int moistSensorPin = A3;

void ActivateWaterPump(int millisecondsToPump)
{
  digitalWrite(PUMP_PIN, HIGH);
  Serial.println("The Water Pump is ON!");
  delay(3000);
  digitalWrite(PUMP_PIN, LOW);
  Serial.println("The Water Pump is OFF!");
  delay(1000);
}
double GetHumidityPrecent()
{
  double humidityValue = analogRead(A2);
  Serial.print("humidity: ");
  double humidityProcent = (100-(humidityValue/1023.00)*100);
  Serial.print(humidityProcent);
  Serial.println("%");
  delay(1000);
  return humidityProcent;
}
int GetLightValue(){
  int lightValue = analogRead(A0);
  Serial.print("lightValue: ");
  Serial.println(lightValue);
  return lightValue;
}

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(moistSensorPin, INPUT);
  pinMode(lightSensorPin, INPUT);
}
 
void loop() {
double humidityProcent = GetHumidityPrecent();
int lightValue = GetLightValue();
  if (humidityProcent < 50.00 && lightValue < 500)
  {
    ActivateWaterPump(3000);
  }
}