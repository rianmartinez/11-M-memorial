const int ledPin=32;                 //Connect the LED Grove module to Pin32, Digital 32
void lightSensor() 
{
    Serial.begin(9600);                //Start the Serial connection
    pinMode(ledPin,INPUT);            //Set the LED on Digital 32 as an OUTPUT
}
void loopGrove() {
  
  analogValue=analogRead(32);
  Serial.print("Leyendo sensor luminico = ");
  Serial.print(analogValue);   

  if (analogValue < 10) {
    Serial.println(" - Sin luz");
  } else if (analogValue < 200) {
    Serial.println(" - Oscuro");
  } else if (analogValue < 500) {
    Serial.println(" - Poca luz");
  } else if (analogValue < 800) {
    Serial.println(" - Luz normal");
  } else {
    Serial.println(" - Mucha luz");
  }

  delay(500);
}
