//After orienting oneself with controlling a single propellor, the quadracopter
//becomes just a matter of copypasta.


////Notes about writeMicroseconds:

//Use this like a standard servo
//The input range is 1000-2000 (1500 is midpoint)

//This sketch will illustrate the usage
//just open the serial monitor while running this
//code to see how writeMicroseconds maps to 
//motor velocity & direction

#include <Servo.h> 

Servo esc;

void setup() 
{ 
  esc.attach(9);
  esc.writeMicroseconds(1000);  
  Serial.begin(9600);
} 

void loop() {

  int i;
  for ( i = 1000 ; i < 2000 ; i += 100 ) {
    esc.writeMicroseconds(i);
    Serial.println(i);
    delay(1000);
  }

  for ( i = 2000 ; i > 1000 ; i -= 100 ) {
    esc.writeMicroseconds(i);
    Serial.println(i);
    delay(1000);
  }

} 
