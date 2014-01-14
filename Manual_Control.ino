//After orienting oneself with controlling a single propellor, controlling the quadracopter becomes cake.

////Notes about writeMicroseconds:

//Use this like a standard servo
//The input range is 1000-2000 (1500 is midpoint)

// leave the potentiometer at 0 (writeMicroseconds being 1000), for about 5 seconds or after the two beeps, then ramp up.


//$12 ESC used: http://www.amazon.com/NEEWER%C2%AE-Brushless-Motor-Speed-Controller/dp/B00CIQ0TYQ/ref=sr_1_2?ie=UTF8&qid=1389724628&sr=8-2&keywords=esc

#include <Servo.h>

int reading = 0;
int throttle = 0;

Servo motor;

void setup() {

  pinMode(14,OUTPUT);
  pinMode(18,OUTPUT);

  digitalWrite(14, HIGH);
  digitalWrite(18, LOW);

  motor.attach(9);

  Serial.begin(9600);

}

void loop() {

  reading = analogRead(2);
  throttle = map(reading,0,1024,1000,2000);
  Serial.print(throttle); Serial.print(" "); Serial.println(reading);
  motor.writeMicroseconds(throttle);
  delay(10);

}
