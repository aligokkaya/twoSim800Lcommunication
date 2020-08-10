#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library


String textSms,numberSms;
uint8_t index1;
uint8_t role=13; // use what you need 
bool error;


void setup(){
 
pinMode(role,OUTPUT); 
digitalWrite(role,HIGH);

    Serial.begin(9600); // only for debug the results . 
    Sim800l.begin(); // initializate the library. 
   // Sim800l.reset();
    //don't forget to catch the return of the function delAllSms! 
    error=Sim800l.delAllSms(); //clean memory of sms;   
}

void loop(){
    textSms=Sim800l.readSms(1); //read the first sms
    
    if (textSms.indexOf("OK")!=-1) //first we need to know if the messege is correct. NOT an        
        {           
        if (textSms.length() > 7)  // optional you can avoid SMS empty
            {
                
                numberSms=Sim800l.getNumberSms(1);  // Here you have the number
                //for debugin
                Serial.println(numberSms); 
                textSms.toUpperCase();  // set all char to mayus ;)

                if (textSms.indexOf("TURNON-1")!=-1){
                    Serial.println("LED TURN ON");
                    digitalWrite(role,0);
                }
                else if (textSms.indexOf("TURNOFF-0")!=-1){
                    Serial.println("LED TURN OFF");
                    digitalWrite(role,1);

                }
                else{
                    Serial.println("Not Compatible ...sorry.. :D");
                }


            Sim800l.delAllSms(); //do only if the message is not empty,in other case is not necesary
             //delete all sms..so when receive a new sms always will be in first position
            } 



        }
    }
 
