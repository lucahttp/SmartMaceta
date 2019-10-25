// Sensor de Humedad   
      
// Conectamos el sensor de la siguiente forma:      
// GND    -> GND      
// VCC    -> 5V      
// DAT    -> A0    
// Por ejemplo conectamos a las entrada Analógica 0      
// http://arubia45.blogspot.com.es/     

  int data;
// Descripción de valores del Sensor

// 0  -300     Seco 
// 300-700     Húmedo
// 700-950     En Agua
const int relay_pin = 8;
const int buzzer_pin = 10;
const int tilt_pin = 11;
const int humidity_pin = 8;
int trigger_humedad = NULL;

int Valor;

void setup(){
  pinMode(relay_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(tilt_pin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Smart Maceta");


  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite (LED_BUILTIN, LOW); //initially set to low
  
}

   void loop(){
      read_serial();
      Serial.print("Sensor de Humedad valor:");
      Valor = analogRead(humidity_pin);
      Serial.print(Valor);
      if (Valor <= 300){
        trigger_humedad=0;
        Serial.println(" Encharcado");
        digitalWrite(relay_pin, LOW);
        mqttduino("relay",String(digitalRead(relay_pin)));
      }
      if ((Valor > 300) and (Valor <= 700)){
        Serial.println(" Humedo, no regar");
        mqttduino("relay",String(digitalRead(relay_pin)));

       
      }
      if (Valor > 700){
        if(trigger_humedad==0){
            Serial.println(" Seco, necesitas regar");
            mqttduino("relay",String(digitalRead(relay_pin)));
            tone(buzzer_pin, 1000, 500);
            digitalWrite(relay_pin, HIGH);
            mqttduino("ya-regado","recien se regó la maceta");
            trigger_humedad=1;
        }

      }
      delay(1000);
   }

// https://www.luisllamas.es/arduino-humedad-suelo-fc-28/
// http://msrobotics.net/index.php/laboratorio-ard/147-sensor-humedad-de-una-superficie-o-terreno-con-arduino



void mqttduino (String channel, String data)
{
    Serial.print("@");
    Serial.print("mqtt");
    Serial.print(",");
    Serial.print(channel);
    Serial.print(",");
    Serial.println(data);
    delay(10);
}

/*

  int data;

void setup() 
{ 
  Serial.begin(9600); 
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite (LED_BUILTIN, LOW); //initially set to low
  Serial.println("This is my First Example.");
}
 
void read_serial() 
{
while (Serial.available())
  {
    data = Serial.read();
  }

  if (data == '1')
  digitalWrite (LED_BUILTIN, HIGH);

  else if (data == '0')
  digitalWrite (LED_BUILTIN, LOW);

}


*/


void read_serial() 
{
    while (Serial.available())
      {
        data = Serial.read();
      }
    
      if (data == '1')
      digitalWrite (LED_BUILTIN, HIGH);
    
      else if (data == '0')
      digitalWrite (LED_BUILTIN, LOW);

}
