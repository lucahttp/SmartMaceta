bool r = true;

void setup(){
  Serial.begin(9600);
}
void loop(){
  if(Serial.available()){         //From RPi to Arduino
    if(Serial.read()=="@"){
      !r;
      if(r==true){
          digitalWrite(LED_BUILTIN, HIGH);
      }
      else{
          digitalWrite(LED_BUILTIN, LOW);

      }
      //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
      /*
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(1000);                       // wait for a second
      */
    }
    //Serial.println(Serial.read());
    //r = r * (Serial.read() - '0');  //conveting the value of chars to integer
  }
}
