int photoresistorPin = A0; 
int buzzerPin = 9;  
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

void setup(){
  pinMode(buzzerPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);

  Serial.begin(9600);

  while(millis() < 5000){
    sensorValue = analogRead(photoresistorPin);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
}

void loop(){
  sensorValue = analogRead(photoresistorPin);
  int var = map(sensorValue, sensorLow, sensorHigh, 0, 1);

  if(var == 0){
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Object Detected!");
  }

  if(var == 1){
    digitalWrite(buzzerPin, LOW);
  }
  delay(20);
}