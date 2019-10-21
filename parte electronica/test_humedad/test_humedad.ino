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

int Valor;

void setup(){
  Serial.begin(9600);
  Serial.println("http://arubia45.blogspot.com.es");
}

   void loop(){
      Serial.print("Sensor de Humedad valor:");
      Valor = analogRead(0);
      Serial.print(Valor);
      if (Valor <= 300)
        Serial.println(" Seco, necesitas regar");
      if ((Valor > 300) and (Valor <= 700))
        Serial.println(" Humedo, no regar");
      if (Valor > 700)
        Serial.println(" Encharcado");
      delay(1000);
   }

// https://www.luisllamas.es/arduino-humedad-suelo-fc-28/
// http://msrobotics.net/index.php/laboratorio-ard/147-sensor-humedad-de-una-superficie-o-terreno-con-arduino
