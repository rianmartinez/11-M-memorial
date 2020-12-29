#define pinRELE 2

void releLucesLed() {  
  pinMode(pinRELE, OUTPUT);
}

void loopReleLucesLed() {
   if (analogValue < 200) { //Consideramos que cuando se empieza hacer oscuro encendemos la luz
     digitalWrite(pinRELE, HIGH);
   }
   else {
    digitalWrite(pinRELE, LOW);
   }
  
}
