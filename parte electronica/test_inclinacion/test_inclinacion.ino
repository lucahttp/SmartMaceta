int inPin = 2;
int outPin = 13;
int lectura;
int previo = LOW;

long time = 0;            // Para guardar la hora de la inversion de valor
long debounce = 50;       // Tiempo de rebote

void setup()
   {  pinMode(inPin, INPUT_PULLUP);
      pinMode(outPin, OUTPUT);
   }

void loop()
   {  lectura = digitalRead(inPin);
      if (lectura != previo)     // Si hay cambio en la lectura
          time = millis();
      if ((millis() - time) > debounce)
           digitalWrite(outPin, lectura);

      previo = lectura ;
   }



//https://www.prometec.net/tilt-switch/
