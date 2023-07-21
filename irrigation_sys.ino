#include <Servo.h>

int levelValue = 0;  // holds the water level sensor value
int waterPin = A5; // water level sensor pin used
int msvalue = 0; // holds the moisture sensor value
int msensor = A5; // moisture sensor pin used
int redled = 5;
int greenled = 6;
int yellowled = 7;
int empty = 9;
boolean flag = false;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(msensor, INPUT);
  myservo.attach(8);
}

void loop() {
  levelValue = analogRead(waterPin);
  msvalue = analogRead(msensor);
  
  //need of water and water tank full
  
  if ((msvalue >= 500) && ( flag == false ) && (levelValue > 300))
  {
      Serial.println("Plant needs water");
      digitalWrite(redled, HIGH);
      digitalWrite(greenled, LOW);
      digitalWrite(yellowled, LOW);
      myservo.write(90);
      flag = true;
      delay(1000);  
    }
    
    //no need of water and water tank full
    
    else if ((msvalue <= 300) && ( flag == true )&& (levelValue>300))
    {
        Serial.println("Plant does not need water");
        digitalWrite(redled, LOW);
        digitalWrite(greenled, HIGH);
        digitalWrite(yellowled, LOW);
        myservo.write(0);
        flag = false;
        delay(1000);
        }
      
      //need of water and water tank empty
      
      else if ((msvalue >= 500) && ( flag == false ) && (levelValue<100))
      {
        Serial.println("Plant does not need water");
        digitalWrite(redled, HIGH);
        digitalWrite(greenled, LOW);
        digitalWrite(yellowled, LOW);
        myservo.write(0);
        flag = false;
        delay(1000);
        }
      //no need of water and water tank empty 
      else{
          digitalWrite(empty, HIGH);
         myservo.write(0);
        }   
   Serial.print("The water level is : ");
   Serial.println(levelValue);
   delay(4000);
   Serial.print("The moisture level is : ");
   Serial.println(msvalue);
   delay(4000);
}
