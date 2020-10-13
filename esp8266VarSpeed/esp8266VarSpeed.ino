#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

//Found in BLYNK --> Gear on top right --> Under auth token is
//the list of letters and numbers you replace "auth token" with
char auth[] = "oGS79w1bZfUEsPOusxCQFODyAfAcHag7"; 

//Phone name
char ssid[] = "Bruh iPhone";

//Hotspot Password
char pass[] = "12345678";

Servo motor;
Servo servoRudder;
Servo servoAileronL;
Servo servoAileronR;
Servo servoElevator;

int speedMultiplier;
int rudderTrim;
int aileronTrim;
int elevatorTrim;

int rudderPos;
int aileronLPos;
int aileronRPos;
int elevatorPos;

int rudderJoystick;
int aileronLJoystick;
int aileronRJoystick;
int elevatorJoystick;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  motor.attach(2); //nodeMCU port D4
  servoRudder.attach(14); //nodeMCU port D5
  servoAileronL.attach(12); //nodeMCU port D6
  servoAileronR.attach(13); //nodeMCU port D7
  servoElevator.attach(15); //nodeMCU port D8

  Blynk.virtualWrite(V1, 75);
  Blynk.virtualWrite(V5, 0);
  Blynk.virtualWrite(V6, 5);
  Blynk.virtualWrite(V7, 5);
  Blynk.virtualWrite(V8, 5);
}

void loop()
{
  Blynk.run();

  rudderPos = servoRudder.read();
  aileronLPos = servoAileronL.read();
  aileronRPos = servoAileronR.read();
  elevatorPos = servoElevator.read();
  
  Serial.print("Rudder Position: ");
  Serial.println(rudderPos);
  Serial.print("joystick Position: ");
  Serial.println(rudderJoystick);
  Serial.print("AileronL Position: ");
  Serial.println(aileronLPos);
  Serial.print("AileronR Position: ");
  Serial.println(aileronRPos);
  Serial.print("Elevator Position: ");
  Serial.println(elevatorPos);

  if(rudderPos < rudderJoystick) {
    servoRudder.write(rudderPos + speedMultiplier);
  }
  if(rudderPos > rudderJoystick) {
    servoRudder.write(rudderPos - speedMultiplier);
  }

  if(aileronLPos < aileronLJoystick) {
    servoAileronL.write(aileronLPos + speedMultiplier);
  }
  if(aileronLPos > aileronLJoystick) {
    servoAileronL.write(aileronLPos - speedMultiplier);
  }
  
  if(aileronRPos < aileronRJoystick) {
    servoAileronR.write(aileronRPos + speedMultiplier);
  }
  if(aileronRPos > aileronRJoystick) {
    servoAileronR.write(aileronRPos - speedMultiplier);
  }

  if(elevatorPos < elevatorJoystick) {
    servoElevator.write(elevatorPos + speedMultiplier);
  }
  if(elevatorPos > elevatorJoystick) {
    servoElevator.write(elevatorPos - speedMultiplier);
  }
}

BLYNK_WRITE(V1) {
  int motorSpeed = 2 * (param.asInt() - 90);
  motor.write(motorSpeed); 
}
BLYNK_WRITE(V2) {
  rudderJoystick = param.asInt() + rudderTrim;
}
BLYNK_WRITE(V4) {
  aileronLJoystick = param.asInt() + aileronTrim;
  aileronRJoystick = -(param.asInt() + aileronTrim) + 180;
}
BLYNK_WRITE(V3) {
  elevatorJoystick = param.asInt() + elevatorTrim; 
}
BLYNK_WRITE(V5) {
  speedMultiplier = 2 * param.asInt() + 1;
}
BLYNK_WRITE(V6) {
  rudderTrim = 4 * param.asInt() - 20; 
}
BLYNK_WRITE(V7) {
  aileronTrim = 4 * param.asInt() - 20; 
}
BLYNK_WRITE(V8) {
  elevatorTrim = 4 * param.asInt() - 20; 
}
