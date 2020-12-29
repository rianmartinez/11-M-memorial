#define LED_BUILTIN 22


void conectarWifi() {
Serial.begin(115200);
WiFi.begin(ssid, password);
Serial.println("Conectando . . .");

pinMode(LED_BUILTIN, OUTPUT);

 while(WiFi.status() != WL_CONNECTED){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  Serial.println(".");
  delay(500);
}
Serial.println("\n¡Conectado!");
Serial.print("Dirección IP:");
Serial.println(WiFi.localIP());
}
