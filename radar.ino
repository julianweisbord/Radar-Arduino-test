#include <Arduino.h>
#include <Servo.h>
#define trigPin 12
#define echoPin 11

Servo radarServo;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
radarServo.attach(9); //signal pin for pwm
Serial.begin(9600); //console communication
}

long ultra_sonic_pulse(){
  // play with delay
  // delay(300);
  long time, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time =pulseIn(echoPin, HIGH);
  //speed of sound .034029 cm/10^-6 s
  distance = (.034029*time)/2;
  //0-10m range
  if(distance > 10000 || distance <= 0){
    Serial.println("Distance is too large or too small.");
  }
  else{
    Serial.println(distance);
    Serial.print(" cm\n");
  }  
  return distance;
  }
    
void loop() {
  // put your main code here, to run repeatedly:
  long distance = ultra_sonic_pulse();

}
