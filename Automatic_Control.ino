#include <Servo.h>

//this is an example of how to create a one time sequence for the
//motor controller

//ESC NOTES:
//maximum throttle is usually 2000
//min throttle (no throttle) 1000 usually

// Initialization settings

int init_throttle = 1000;
int init_delay = 3000;

// Final PWM Objective

int final_throttle = 2000;
int time_until_final = 5000;
int time_at_final = 8000;
int throttle_increment = 50;

int throttle;

Servo motor;

void setup() {

  motor.attach(9);

  Serial.begin(9600);

  //begin init sequence

  throttle = init_throttle;
  motor.writeMicroseconds(throttle);
  delay(init_delay);

  //ramp to target speed
  // explanation: time_until_final = number_of_steps * delay_per_step; 
  // therefore, delay_per_step = time_until_final/(number_of_steps);
  int number_of_steps = ( final_throttle - init_throttle )/ (throttle_increment );
  int delay_per_step = time_until_final / ( number_of_steps );

  for ( throttle = init_throttle ; throttle <= final_throttle ; throttle += throttle_increment ) {
      motor.writeMicroseconds(throttle);
      Serial.println(throttle);
      delay(delay_per_step);
    }
  for ( throttle = final_throttle ; throttle >= init_throttle ; throttle -= throttle_increment ) {
      motor.writeMicroseconds(throttle);
      Serial.println(throttle);
      delay(delay_per_step);
  }
  Serial.println("Sequence Completed");
}

void loop() {

  delay(1000);

}
