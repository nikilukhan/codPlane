#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

//Found in BLYNK --> Gear on top right --> Under auth token is
//the list of letters and numbers you replace "auth token" with
char auth[] = "customAuthenticator"; 

//Phone name
char ssid[] = "phoneName";

//Hotspot Password
char pass[] = "hotspotPassword";

Servo motor;
Servo servoRudder;
Servo servoAileronL;
Servo servoAileronR;
Servo servoElevator;

float speedMultiplier;
float rudderTrim;
float aileronTrim;
float elevatorTrim;

void setup()
{
  motor.write(90);
  delay(10000);
  motor.write(0);
  
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  motor.attach(2); //nodeMCU port D4
  servoRudder.attach(14); //nodeMCU port D5
  servoAileronL.attach(12); //nodeMCU port D6
  servoAileronR.attach(13); //nodeMCU port D7
  servoElevator.attach(15); //nodeMCU port D8

  Blynk.virtualWrite(V1, 90);
  Blynk.virtualWrite(V5, 0);
  Blynk.virtualWrite(V6, 5);
  Blynk.virtualWrite(V7, 5);
  Blynk.virtualWrite(V8, 5);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1) {
  motor.write(map(param.asInt(),0,180,0,120)); 
}
BLYNK_WRITE(V2) {
  servoRudder.write(param.asInt()+rudderTrim); 
}
BLYNK_WRITE(V4) {
  servoAileronL.write(param.asInt()+aileronTrim);
  servoAileronR.write(-(param.asInt()+aileronTrim) + 180); 
}
BLYNK_WRITE(V3) {
  servoElevator.write(param.asInt()+elevatorTrim); 
}
BLYNK_WRITE(V5) {
  speedMultiplier = 5 * param.asInt()+1;
}
BLYNK_WRITE(V6) {
  rudderTrim = 4*param.asInt()-20; 
}
BLYNK_WRITE(V7) {
  aileronTrim = 4*param.asInt()-20; 
}
BLYNK_WRITE(V8) {
  elevatorTrim = 4*param.asInt()-20; 
}
