void sensorRayos() 
{
  Serial.begin(9600);
}
 
void loopRayos() 
{
  float sensorVoltage; 
  float sensorValue;
 
  sensorValue = analogRead(13);
  sensorVoltage = sensorValue/1024*5.0;
  Serial.print("sensor reading = ");
  Serial.print(sensorValue);
  Serial.println("");
  Serial.print("sensor voltage = ");
  Serial.print(sensorVoltage);
  Serial.println(" V");
  delay(1000);
}
