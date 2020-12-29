#define TOKENLUZ "KiSclpYCCHeFF15Jtygo"

void loopmqtt() {

  analogValueLuz=analogRead(32);
  analogValueUV=analogRead(13);
  digitalValueAgua=digitalRead(4);
  delay(quant);
  send_passed += quant;


  // Reconnect to ThingsBoard, if needed
  if (!tb.connected()) {
  // Connect to the ThingsBoard
      Serial.print("Connecting to: ");
      Serial.print(THINGSBOARD_SERVER);
      Serial.print(" with token ");
      Serial.println(TOKENLUZ);
      if (!tb.connect(THINGSBOARD_SERVER, TOKENLUZ)) {
            Serial.println("Failed to connect");
            return;
          }
  }

  if (send_passed > send_delay) {
  Serial.println("Enviando datos del sensor de luz al thingsboard");
  Serial.println("Luz: " + String(analogValueLuz));
  tb.sendTelemetryFloat("luz", analogValueLuz);
  Serial.println("Enviando datos de rayos UV al thingsboard");
  Serial.println("Rayos UV: " + String(analogValueUV));
  tb.sendTelemetryFloat("Rayos UV", analogValueUV);
  Serial.println("Enviando datos de agua al thingsboard");
  Serial.println("Agua en la fuente: " + String(digitalValueAgua));
  tb.sendTelemetryFloat("Agua ", digitalValueAgua);
  delay(1000);
  }
} 
