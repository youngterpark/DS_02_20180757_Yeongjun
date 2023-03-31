#include <Stepper.h>

// Define the number of steps per revolution
const int stepsPerRevolution = 200 ; // 360/1.8 = 200

// Initialize the stepper motor with the number of steps and pins
Stepper Left_step(200, 8, 9, 10, 11);
Stepper Right_step(200, 2, 3, 4, 5);

void setup() {
  Serial.begin(9600);
  // Set the speed of the stepper motor in revolutions per minute (RPM)
  Right_step.setSpeed(60);
  Left_step.setSpeed(60);
  Serial.println("Serial begin");
}

void loop()
{
  Serial.println("loop begin");

  // 전진
  int looptime = 0;
  Right_step.step(-stepsPerRevolution); Left_step.step(stepsPerRevolution);
  whlie(looptime<1000)
  {
    if (Right_step.steps_left > 0 && Left_step.steps_left > 0)
    {
      Right_step.moveStep();
      Left_step.moveStep();
    }
    delay(1);
    looptime++;
  }
  delay(1000);

  // 우회전
  int looptime = 0;
  Right_step.step(stepsPerRevolution); Left_step.step(stepsPerRevolution);
  whlie(looptime<1000)
  {
    if (Right_step.steps_left > 0 && Left_step.steps_left > 0)
    {
      Right_step.moveStep();
      Left_step.moveStep();
    }
    delay(1);
    looptime++;
  }
  delay(1000);

  // 좌회전
  int looptime = 0;
  Right_step.step(-stepsPerRevolution); Left_step.step(-stepsPerRevolution);
  whlie(looptime<1000)
  {
    if (Right_step.steps_left > 0 && Left_step.steps_left > 0)
    {
      Right_step.moveStep();
      Left_step.moveStep();
    }
    delay(1);
    looptime++;
  }
  delay(1000);

  // 후진
  int looptime = 0;
  Right_step.step(stepsPerRevolution); Left_step.step(-stepsPerRevolution);
  whlie(looptime<1000)
  {
    if (Right_step.steps_left > 0 && Left_step.steps_left > 0)
    {
      Right_step.moveStep();
      Left_step.moveStep();
    }
    delay(1);
    looptime++;
  }
  delay(1000);

  // 끄기
  for(int i=2; i<6; i++)
  {
    digitalWrite(i,LOW); digitalWrite(i+6,LOW);
  }
  
  // end the loop
  while(true){}
}

