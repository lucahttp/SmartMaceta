void setup(){
  Serial.begin(9600);
}

void loop(){
  for (int i = 0; i <= 5; i++) {
    Serial.print("#");
    Serial.print("GG");
    Serial.println(i);   
    delay(100);
    Serial.print("%");
    Serial.print("ICI");
    Serial.println(i);   
    delay(100);
    Serial.print("@");
    Serial.print("PICI");
    Serial.println(i);   
    delay(100);
  }
}
