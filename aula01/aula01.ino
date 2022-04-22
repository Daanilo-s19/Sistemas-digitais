byte LED1 = 7;
byte LED2 = 8;

long millisAnterior, millisAnterior2;

const int basicInterval = 3000;
const int interval = basicInterval /3;
const int interval2 = interval/2;
 
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  serialBegins()
  millisAnterior = millis();
  millisAnterior2 = millis();
}

void loop() {
   if(millis() - millisAnterior > interval) {
    millisAnterior = millis();    
    digitalWrite(LED1,!digitalRead(LED1));
   }

  if(millis() - millisAnterior2 > interval2) {
    millisAnterior2 = millis();    
    digitalWrite(LED2,!digitalRead(LED2));
   }
   
}
const setPinMode()
