#include <Servo.h>

int PWM_ROLL = 11; //Define Digital PIN
int PWM_PITCH = 10; //Define Digital PIN
int PWM_THROTTLE = 12;//11; //Define Digital PIN
int PWM_YAW = 8;//10; //Define Digital PIN
int a=1045;


Servo Throttle;
Servo Roll;
Servo Pitch;
Servo Yaw;

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 13; // Echo Pin of Ultrasonic Sensor

void setup() {
  pinMode(PWM_ROLL, INPUT);
  pinMode(PWM_PITCH, INPUT);
  pinMode(PWM_THROTTLE, INPUT);
  pinMode(PWM_YAW, INPUT);
  Throttle.attach(9);
  Roll.attach(6);
  Pitch.attach(5);
  Yaw.attach(3);
/*
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);*/
  Serial.begin(57600);
}

void loop() {
  int roll = pulseIn(PWM_ROLL, HIGH); //Read PWM Pulse
  int pitch = pulseIn(PWM_PITCH, HIGH); //Read PWM Pulse
  int throttle = pulseIn(PWM_THROTTLE, HIGH); //Read PWM Pulse
  int yaw = pulseIn(PWM_YAW, HIGH); //Read PWM Pulse

  Serial.print(" PWM CH1 Roll: ");
  Serial.print(roll);
  Serial.print(" PWM CH2 Pitch: ");
  Serial.print(pitch);
  Serial.print(" PWM CH3 Throttle: ");
  Serial.println(throttle);
  Serial.print(" PWM CH1 Yaw: ");
  Serial.print(yaw);
    /*
   analogWrite(A0, (roll-864)*255/986);
   analogWrite(A1, (pitch-992)*255/990);
   analogWrite(A2, (throttle-1045)*255/939);
   analogWrite(A3, (yaw-995)*255/976);
   
*/
long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
if(inches >= 5 && inches<=7)
  {
    //Serial.println("Closing in");
    a=1500;
  }
else if(inches >= 8 && inches<=10)
{
  a=1200;
}
else if(inches > 10){
a=0;
}
Serial.println("Distance approached: "+inches);
  Throttle.writeMicroseconds(a);
  Roll.writeMicroseconds(roll);
  Yaw.writeMicroseconds(yaw);
  Pitch.writeMicroseconds(pitch);


}



long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
