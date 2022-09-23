#include <Arduino.h>
//I, Sadeva Chanuka Karunanayaka, student number 000776370, certify that all code submitted is my own work;
//that I have not copied it from any other source.  I also certify that I have not allowed my work to be copied by others.
 
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200); 
}

void loop() {

int iVal; 

 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
 
  //convert to analogue temperature value using math 
  double temperatureVal = (iVal/1024.00)*50;

  String judgement = "";
  //get judgement string based on what the temperature value is
  if(temperatureVal<10.00){
    judgement="Cold!";
  }
  else if (temperatureVal>=10.0&&temperatureVal<15.0){
    judgement="Cool";
  }
  else if (temperatureVal>=15.0&&temperatureVal<25.0){
    judgement="Perfect";
  }else if (temperatureVal>=25.0&&temperatureVal<30.0){
    judgement="Warm";
  }else if (temperatureVal>=30.0&&temperatureVal<35.0){
    judgement="Hot";
  }else{
    judgement="Too Hot!";
  }


  // print value to the USB port 
  Serial.println("Digitized Value of " + String(iVal) +" is equivalent to a temperature input of  = "+String(temperatureVal)+" deg, which is "+judgement); 
 
  // wait 0.5 seconds (500 ms) 
  delay(500); 
}