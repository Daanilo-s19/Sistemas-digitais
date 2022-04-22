int analogValue = 0;

byte LED1 = 4;
byte  buttonPin = 2;

volatile byte turnOff = false;

long millisAnterior;
const int interval = 3000;

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(buttonPin), setTurnOff, FALLING);

  millisAnterior = millis();

}

void setTurnOff() {
  turnOff = true;
}

void loop() {

  analogValue = analogRead(A0);

    Serial.println(analogValue);
  const int isBlink = (millis() - millisAnterior) % 2 == 0 ;


  if (analogValue < 400) {
    digitalWrite(LED1, HIGH);
    turnOff = true;
  } else if (turnOff) {
    digitalWrite(LED1, LOW); 
    turnOff = false;
  }

//  if (turnOff) {
//    Serial.println(analogValue);
//    Serial.println(turnOff);
//
//    if (isBlink) {
////      Serial.println("LOW");
//      digitalWrite(LED1, LOW );
//    } else {
//      digitalWrite(LED1, HIGH );
////      Serial.println("HIGH");
//    }

  //}


  delay(300);
}
