#include <AccelStepper.h>
#define STEPS_PER_REVOLUTION 200

AccelStepper Left_step(AccelStepper::FULL4WIRE, 8, 9, 10, 11);
AccelStepper Right_step(AccelStepper::FULL4WIRE, 2, 3, 4, 5);

int CW = STEPS_PER_REVOLUTION;
int CCW = -STEPS_PER_REVOLUTION;

// 초음파
const int triggerPin = 12;
const int echoPin = 13;
const int avgnum = 5; // 보간할 크기
long readings[avgnum] = {0,0,0,0,0};
int index = 0;
long total = 0;
long average = 0;

void setupUltra(){
  //Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
long UltraSonic(int index) 
{
  digitalWrite(triggerPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW); 
  long duration = pulseIn(echoPin, HIGH); // 측정 시간
  long distance = duration / 29 / 2; // 측정시간 * (속력) / 2 (반틈)

  // 필터: 측정시마다 index증가시킴(4->0), readings는 최근 5개 값 저장
  if(index==0){readings[index]=distance;}
  else if(index==1){readings[index]=distance;}
  else if(index==2){readings[index]=distance;}
  else if(index==3){readings[index]=distance;}
  else if(index==4){readings[index]=distance;}

  // 5개 값 중 최솟값, 최댓값 빼고 3개 평균
  long min = readings[0];
  long max = readings[0];
  int minindex = 0;
  int maxindex = 0;
  for (int i = 1; i < 5; i++) {
    if (readings[i] < min) {
      minindex = i;
    }
    if (readings[i] > max) {
      maxindex = i;
    }
  }
  total = readings[0]+readings[1]+readings[2]+readings[3]+readings[4]-readings[maxindex]-readings[minindex];
  average = total/(avgnum-2);
  return average;
}

void setup() {
  //Serial.begin(9600);
  setupUltra(); // 초음파 셋업

  Right_step.setMaxSpeed(600);
  Left_step.setMaxSpeed(600);
  Right_step.setAcceleration(100.0);
  Left_step.setAcceleration(100.0);
}

void loop() {
  int rev = 20; // 20바퀴 회전
  
  Right_step.setCurrentPosition(0); // 현재 위치 초기화
  Left_step.setCurrentPosition(0);

  Right_step.moveTo(rev*CW); // 우측 모터 CW 회전
  Left_step.moveTo(rev*CCW); // 좌측 모터 CCW 회전

  while (Right_step.distanceToGo() != 0 || Left_step.distanceToGo() != 0) {
    long dist = UltraSonic(index); // 거리측정
    // 초음파 index update
    index++;
    if (index >= avgnum)
    {
      index = 0;
    } 
    if (dist < 50 && dist > 0)
    {
      Right_step.stop();
      Left_step.stop();
      delay(3000);
      break;
    }
    Right_step.run();
    Left_step.run();
  }  
}

