// Sensor de Humedad   
      
// Conectamos el sensor de la siguiente forma:      
// GND    -> GND      
// VCC    -> 5V      
// DAT    -> A0    
// Por ejemplo conectamos a las entrada Analógica 0      
// http://arubia45.blogspot.com.es/     


// Descripción de valores del Sensor

// 0  -300     Seco 
// 300-700     Húmedo
// 700-950     En Agua
const int relay_pin = 8;
const int buzzer_pin = 10;
const int tilt_pin = 11;
const int humidity_pin = 8;

int Valor;

void setup(){
  pinMode(relay_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(tilt_pin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Smart Maceta");
  
}

   void loop(){
      Serial.print("Sensor de Humedad valor:");
      Valor = analogRead(humidity_pin);
      Serial.print(Valor);
      if (Valor <= 300){
        Serial.println(" Seco, necesitas regar");
        
        tone(buzzer_pin, 1000, 500);
        digitalWrite(relay_pin, HIGH);
      }
      if ((Valor > 300) and (Valor <= 700)){
        Serial.println(" Humedo, no regar");
       
      }
      if (Valor > 700){
        Serial.println(" Encharcado");
        digitalWrite(relay_pin, LOW);

      }
      delay(1000);
   }

// https://www.luisllamas.es/arduino-humedad-suelo-fc-28/
// http://msrobotics.net/index.php/laboratorio-ard/147-sensor-humedad-de-una-superficie-o-terreno-con-arduino
