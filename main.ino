int irPin=3;
int LEDPin=13;
int white=0;
int black=0;
int count=0;
void setup() {
  pinMode(LEDPin,OUTPUT);
  pinMode(irPin,INPUT);
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
}
