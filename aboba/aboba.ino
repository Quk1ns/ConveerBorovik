#include <AmperkaServo.h>

#include <NewPing.h>
#include "Adafruit_TCS34725.h"


Adafruit_TCS34725 colorSensor;
constexpr uint8_t PIN_BACKLIGHT = 12;

AmperkaServo servo;
constexpr uint8_t SERVO_PIN = 3;


#define TRIGGER_PIN  10
#define ECHO_PIN     11
#define MAX_DISTANCE 400
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


#define SPEED_1      5 
#define DIR_1        4
#define SPEED_2      6
#define DIR_2        7

int sasha;
int sasha2;
int sasha3;
int sasha4;
int nikita8;
String aboba;
String color1;
String color2;
String color3;
String color4;
void setup() {
  Serial.begin(9600);
  pinMode(PIN_BACKLIGHT, OUTPUT);
  digitalWrite(PIN_BACKLIGHT, HIGH);
  for (int i = 4; i < 8; i++) {     
    pinMode(i, OUTPUT);
  }
  servo.attach(SERVO_PIN, 544, 2400, 0, 180);
  servo.writeAngle(servo.getMidAngle());
} 
 
void loop() {
    if (Serial.available()){
      sasha = Serial.read();
      if (sasha == 51){
        color2 = "Red";
      }
      else if (sasha == 52){
        color2 = "Green";
      }
      else if (sasha == 53){
        color2 = "Blue";
      }
      else if (sasha == 54){
        color2 = "Black";
      }
  }
  if (Serial.available()){
    sasha = Serial.read();
    if(sasha != sasha2){
      if (sasha == 51){
        color1 = "Red";
      }
      else if (sasha == 52){
        color1 = "Green";
      }
      else if (sasha == 53){
        color1 = "Blue";
      }
      else if (sasha == 54){
        color1 = "Black";
      }
    }
    if (sasha == '1'){
      sasha2 = Serial.read();
      nikita8 = Serial.read();
      while((check() > 3 || check() == 0) && nikita8 != '0'){
        Drive();
        nikita8 = Serial.read();
      }
      while(check() < 12 && nikita8 != '0'){
        nikita8 = Serial.read();
        Drive();
      }
      delay(2000);
      float r, g, b;
      colorSensor.getRGB(&r, &g, &b);
      if (r < 100 && g < 90 & b < 100){
        aboba = "Black";
      }
      else if ((r > g) && (r > b)){
        aboba = "Red";}
      else if ((g > r) && (g > b)){
        aboba = "Green";}
      else if ((b > g) && (b > r)){
        aboba = "Blue";
      }
      Serial.println(aboba);
      Serial.println(color1);
      Serial.println(color2);
      if(color1 == aboba){
        servo.writeAngle(servo.getMidAngle() + 30);
      }
      if(color2 == aboba){
        servo.writeAngle(servo.getMidAngle() - 30);
      }
      for(int i = 0; i <= 20; i++){
        if(nikita8 != '0'){
          Drive();
        }
      }
      if(color1 == aboba){
        servo.writeAngle(servo.getMidAngle() - 60);
      }
      if(color2 == aboba){
        servo.writeAngle(servo.getMidAngle() + 60);
      }
      while(nikita8 != '0'){
        nikita8 = Serial.read();
        Drive();
      }
      servo.writeAngle(servo.getMidAngle());
    }
    if(sasha == '9'){
      nikita8 = Serial.read();
      while((check() > 3 || check() == 0) && nikita8 != '0'){
        Drive();
        nikita8 = Serial.read();
      }
      while(check() < 12 && nikita8 != '0'){
        nikita8 = Serial.read();
        Drive();
      }
      delay(500);
      float r, g, b;
      colorSensor.getRGB(&r, &g, &b);
      if (r < 100 && g < 90 & b < 100){
        aboba = "Black";
      }
      else if ((r > g) && (r > b)){
        aboba = "Red";}
      else if ((g > r) && (g > b)){
        aboba = "Green";}
      else if ((b > g) && (b > r)){
        aboba = "Blue";
      }
      if(color1 == aboba){
        servo.writeAngle(servo.getMidAngle() + 30);
      }
      if(color2 == aboba){
        servo.writeAngle(servo.getMidAngle() - 30);
      }
      for(int i = 0; i <= 10; i++){
        Drive();
      }
      delay(100);
      if(color1 == aboba){
        servo.writeAngle(servo.getMidAngle() - 60);
      }
      if(color2 == aboba){
        servo.writeAngle(servo.getMidAngle() + 60);
      }
      colorSensor.getRGB(&r, &g, &b);
      if (r < 100 && g < 90 & b < 100){
        aboba = "Black";
      }
      else if ((r > g) && (r > b)){
        aboba = "Red";}
      else if ((g > r) && (g > b)){
        aboba = "Green";}
      else if ((b > g) && (b > r)){
        aboba = "Blue";
      }
      delay(100);
      servo.writeAngle(servo.getMidAngle());
      if(color1 == aboba){
        servo.writeAngle(servo.getMidAngle() + 30);
      }
      if(color2 == aboba){
        servo.writeAngle(servo.getMidAngle() - 30);
      }
      for(int i = 0; i <= 15; i++){
        Drive();
      }
      if(color1 == aboba){
        servo.writeAngle(servo.getMidAngle() - 60);
      }
      if(color2 == aboba){
        servo.writeAngle(servo.getMidAngle() + 60);
      }
      while(nikita8 != '0'){
        nikita8 = Serial.read();
        Drive();
      }
      servo.writeAngle(servo.getMidAngle());
      Serial.println(color1);
      Serial.println(color2);

    }
  }
}
void Drive(){
    digitalWrite(DIR_1, HIGH);
    analogWrite(SPEED_1, 255);
  
    digitalWrite(DIR_2, HIGH);
    analogWrite(SPEED_2, 255);
    delay(50);
    digitalWrite(DIR_1, LOW);
    analogWrite(SPEED_1, 0);
  
    digitalWrite(DIR_2, LOW);
    analogWrite(SPEED_2, 0);
    delay(100);
}
int check(){
  delay(50);
  return sonar.ping_cm();
}
