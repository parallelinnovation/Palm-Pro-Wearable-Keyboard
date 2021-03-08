#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

const int FSR_PIN = A0; // Pin connected to FSR is A0                 // The resistor I've chosen is 2K ohm
const float VCC = 3.30;                                               // voltage is 3.3V
const float R_DIV = 2000.00;                                          // Measured resistance of the 2k resistor

void setup() 
{
  Serial.begin(9600);
  pinMode(FSR_PIN, INPUT);
//
  drv.begin();  
  drv.selectLibrary(1);
  // I2C trigger by sending 'go' command 
  // default, internal trigger when sending GO command
  drv.setMode(DRV2605_MODE_INTTRIG); 
}
void loop() 
{
  int fsrADC = analogRead(FSR_PIN);
  float force;                                                               
                                                                     
  if (fsrADC != 0)                                                   
  {                                                                    
    float fsrV = fsrADC * VCC / 1023.0;                                                          
    float fsrR = R_DIV * (VCC / fsrV - 1.0);                                                           

    float fsrG = 1.0 / fsrR;                                        
                                                                     
    if (fsrR <= 600) 
      force = (fsrG - 0.00075) / 0.00000032639;
    else
      force =  fsrG / 0.000000642857;
    Serial.println("Force: " + String(force) + " g");
    Serial.println();    
  }
  else
  {
  }
  if ((force<90 ) && (force>75 )){
    Serial.println(F("1 − Strong Click - 100%"));
    drv.go();
    delay(70);
    }
  if ((force<180 ) && (force>165 )){
    Serial.println(F("1 − Strong Click - 100%"));
    drv.go();
    delay(70);
    }
  if ((force<270 ) && (force>255 )){
    Serial.println(F("1 − Strong Click - 100%"));
    drv.go();
    delay(70);
    }
  if ((force<360 ) && (force>345 )){
    Serial.println(F("1 − Strong Click - 100%"));
    drv.go();
    delay(140);
    } 
  else
  {}
//  drv.setWaveform(0, 1);
//  drv.setWaveform(1, 0);      
  delay(10);  
}
