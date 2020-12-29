//FUNCION DE LECTURA DE VALORES DEL SENSOR AGUA 
#define WATER_SENSOR 4 //Conectado al pin 4 del ESP32

void sensorAgua() {  
  pinMode(WATER_SENSOR, INPUT);
}

void loopsensorAgua(){
  int agua; 
  agua = digitalRead(WATER_SENSOR);
  if (agua==1){ //cuando sea 1 considero que no hay agua 
      Serial.println("No hay agua en la superficie del sensor");    
      }
  else{ //si a es 0 hay agua
    Serial.println("Hay agua en la superficie del sensor");
    }
}
