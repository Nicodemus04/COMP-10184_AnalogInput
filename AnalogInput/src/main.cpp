/*
I, Nicodemus Allan, student number 000838957, certify that this material 
is my original work. No other person's work has been used without due 
acknowledgment and I have not made my work available to anyone else.

Date: 2022-09-19
*/

#include <Arduino.h> 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 

double calcVoltage(int iVal) {
  double voltage;
  voltage = iVal * 0.0032226563;
  return voltage;
}

double calcTemp(int iVal) {
  double temp;
  temp = iVal * 0.048828125;
  return temp;
}

String message(double temp){
  String msg;
  if (temp > 35)
  {
    msg = "Too Hot!";
  }
  else if (temp == 30 || temp > 30)
  {
    msg = "Hot";
  }
  else if (temp == 25 || temp > 25)
  {
    msg = "Warm";
  }
  else if (temp == 15 || temp > 15)
  {
    msg = "Perfect";
  }
  else if (temp == 10 || temp > 10)
  {
    msg = "cold";
  }
  else
  {
    msg = "Cold!";
  }
  return msg;
}

void loop() { 
  int iVal; 
  
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
  double voltage = calcVoltage(iVal);
  double temp = calcTemp(iVal);
  String msg = message(temp);

  //voltage
  //Serial.println("Digitized Value of " + String(iVal) + " is equivalent to an Analog Voltage = " + String(calcVoltage(iVal)) + "V."); 
  
  //temp
  Serial.println("Digitized Value of " + String(iVal) + " is equivalent to a temperature input of " + String(calcTemp(iVal)) + " deg. C, which is " + msg); 
  // wait 0.5 seconds (500 ms) 
  delay(2000); 
} 