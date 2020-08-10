#include <NewPing.h>
#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 

#define trigPin 2
#define echoPin 3

#define MAX_DISTANCE 400

Sim800l Sim800l;  //to declare the library
NewPing sonar = NewPing(trigPin, echoPin, MAX_DISTANCE);

char* text;
char* number;
bool error; 
int cm;
int motor=0;

void setup() {
  Serial.begin(9600);
  Sim800l.begin();
}
void loop() {
 
  
  cm= sonar.ping_cm();
  if(cm>0)
  {
//     Serial.print("Distance = ");
//     Serial.print(cm);
//     Serial.println(" cm");
      delay(1000);
       if(cm<50)
       {
        if(motor==1)
        {
         // Serial.print("Motor durdur...");
          text="TURNOFF-0";  //text for the message. 
          number="05510733756"; //change to a valid number.
          error=Sim800l.sendSms(number,text);   
          motor=0;
        }
       }
       if(cm>150)
       {    
        if(motor==0)
        {
         // Serial.print("Motor çalıştır..");
          text="TURNON-1";  //text for the message. 
          number="05510733756"; //change to a valid number.
          error=Sim800l.sendSms(number,text);
          motor=1;
        }
      }
  }  
}
