void setup() {

  Serial.begin(9600); // 시리얼 모니터를 9600bit/s로 설정
 
}

void loop() {

  int a = analogRead(A0); // 토양수분센서인 a 를 아날로그 5번핀에 설정 

  Serial.println(a);  // 수분값인 a를 출력

  delay(2000); // 기다리기

}

