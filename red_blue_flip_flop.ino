void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8,HIGH);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  delay(500);
  digitalWrite(7,LOW);
}
