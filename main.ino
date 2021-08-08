#define trigPin 9
#define echoPin 8
int irPin=3;
int LEDPin=13;
int white=0;
int black=0;
int count=0;
int z;
void setup() {
  pinMode(LEDPin,OUTPUT);
  pinMode(irPin,INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {

if(digitalRead(irPin))
  {
    black++;
    digitalWrite(LEDPin,LOW);
    Serial.println("White");
  }
  else
  {
    white++;
    digitalWrite(LEDPin,HIGH);  
    Serial.println("black");
  }
  if(white>20 && black>10)
  {
    white=0;
    black=0;
    count++;
  }
  Serial.println(count);
  z=ultrasonic();
  delay(1000);
  if(z==1){
    Serial.println("danger");
  }
  else
  Serial.println("safe");
}
int ultrasonic(){
    float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  Serial.println(distance);
  if (distance <= 30  ){
    return 0;
  }
  else if( distance >=500 ){
    return 1;
  }
  else {
    return 1;
    delay(500);
  }
  delay(500);
}
