//Boton
const int buttonPin = 2;
const int ledPin =  8;
const int sensorPin =A8;

int sensorValue = 0;
int buttonState = 0;    

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  buttonState = digitalRead(buttonPin);
  Serial.print("#");
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(100);


  if ((buttonState == LOW ) && (sensorValue >= 570)) {
    digitalWrite(ledPin, LOW);
    } else if ((sensorValue <1024 ) && (buttonState == HIGH )){
    digitalWrite(ledPin, HIGH);
  }
  else if ((sensorValue <= 570 ) && (buttonState == LOW )){
    digitalWrite(ledPin,HIGH);
    delay(3576);
  }
}
