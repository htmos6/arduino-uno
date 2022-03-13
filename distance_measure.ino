#define trigPin 7
#define echoPin 8
#define redPin 11
#define greenPin 12

float distance;
long duration;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); // set trigPin as a output pin, sends sound wave
  pinMode(echoPin, INPUT); // set echoPin as a input pin, receives sound wave
  pinMode(redPin, OUTPUT); // introduce pin of green LED
  pinMode(greenPin, OUTPUT); // introduce pin of red LED
  Serial.begin(9600); // set communication speed
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH); // sends sound wave
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW); // turn off sound wave output

  duration = pulseIn(echoPin, HIGH); // receive sent sound wave
  distance = duration * 0.034 / 2; // find distance in cm

  if (distance < 25.0){
    digitalWrite(greenPin, LOW); 
    delayMicroseconds(1000); // blocks blinking
    digitalWrite(redPin, HIGH); 
  }
  else {
    digitalWrite(redPin, LOW);
    delayMicroseconds(1000); // blocks blinking
    digitalWrite(greenPin, HIGH);  
  }

  Serial.print("Distance: "+String(distance)+"cm\n");
  delay(200); // delay 200 milisecond
}
