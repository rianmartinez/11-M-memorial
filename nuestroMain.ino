#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <math.h>
#include <ThingsBoard.h>


WebServer server(5353); //En mi ordenador corre por ese puerto porque el 8080 esta ocupado

const char* ssid = "SBC";
const char* password = "sbc$2020";
const char* host = "esp32";
int analogValue;
int analogValueLuz;
int analogValueUV;
int digitalValueAgua;

#define THINGSBOARD_SERVER "iot.etsisi.upm.es"
WiFiClient espClient;
ThingsBoard tb(espClient); 
int status = WL_IDLE_STATUS;
int quant = 20;
int send_passed = 0;
int send_delay = 2000;

void conectarWifi();
void basicOTA();
void webUpdater();
void sensorGrove();
void lightSensor();
void loopGrove();
void sensorRayos();
void releLucesLed();
void sensorAgua();

void setup() {
  conectarWifi();
  basicOTA();
  webUpdater();
  lightSensor();
  sensorRayos();
  releLucesLed();
  sensorAgua();
}

void loop(){
  ArduinoOTA.handle();
  server.handleClient();
  loopGrove();
  loopRayos();
  loopReleLucesLed();
  loopmqtt();
  loopsensorAgua();
  delay(500);
}
