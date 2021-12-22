#include <Servo.h>
Servo servo1;
#define RELAY1 4 //Defining the pin 7 of the Arduino for the 4 relay module
int trigPin1 = 6;
int echoPin1 = 7;
int trigPin2 = 8;
int echoPin2 = 9;
void setup() {
 Serial.begin (9600);
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 servo1.attach(5);
 pinMode(RELAY1, OUTPUT); //Defining the pin 7 of the Arduino as output
}
void relayon(){
 digitalWrite(RELAY1,LOW); // This will Turn ON the relay 1
}
void relayoff(){
 24
 digitalWrite(RELAY1,HIGH); // This will Turn OFF the relay 1
}
void servomoter1(){
 servo1.write(90);
}
void servomoter2(){
 servo1.write(0);
}
void secondsensor(){ // This function is for the second sensor.
 int duration2, distance2;
 digitalWrite (trigPin2, HIGH);
 delayMicroseconds (10);
 digitalWrite (trigPin2, LOW);
 duration2 = pulseIn (echoPin2, HIGH);
 distance2 = (duration2/2) / 29.1;
 Serial.print("2nd Sensor: ");
 Serial.print(distance2);
 Serial.print("cm ");
 if (distance2 > 7) { // Change the number for long or short distances.
 servomoter1();
 delay(1000);
 relayon();
 }
 else {
 servomoter2();
 delay(1000);
 relayoff();
 }
 25
}
void loop() {
Serial.println("\n");
 int duration1, distance1;
 digitalWrite (trigPin1, HIGH);
 delayMicroseconds (10);
 digitalWrite (trigPin1, LOW);
 duration1 = pulseIn (echoPin1, HIGH);
 distance1 = (duration1/2) / 29.1;
 Serial.print("1st Sensor: ");
 Serial.print(distance1);
 Serial.print("cm ");
 if (distance1 < 10) { // Change the number for long or short distances.
 secondsensor();
 delay(1000);
 } else {
 servomoter2();
 relayoff();
 return;
}
