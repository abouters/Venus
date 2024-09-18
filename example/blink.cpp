#include <Arduino.h>
#include <FlexCAN_T4.h>
#include "CAN.h"
#include <Venus.h>
#include <Metro.h>

CanControl DriveCan(2);
Venus venus = Venus(&DriveCan, 0);
Metro countup = Metro(500);
bool flag = 0;

void setup() {
  venus.init();
}

void loop(){
  if(countup.check()){
    flag = !flag;
  }
  if(flag){
    venus.setStatus(1, 1);
    venus.setStatus(2, 0);
    venus.setStatus(3, 1);
    venus.setStatus(4, 0);
    venus.setStatus(5, 1);
    venus.setStatus(6, 0);
    venus.setStatus(7, 1);
    venus.setStatus(8, 0);
    venus.setStatus(9, 1);
    venus.setStatus(10, 0);
    venus.setStatus(11, 1);
    venus.setStatus(12, 0);
  }else{
    venus.setStatus(1, 0);
    venus.setStatus(2, 1);
    venus.setStatus(3, 0);
    venus.setStatus(4, 1);
    venus.setStatus(5, 0);
    venus.setStatus(6, 1);
    venus.setStatus(7, 0);
    venus.setStatus(8, 1);
    venus.setStatus(9, 0);
    venus.setStatus(10, 1);
    venus.setStatus(11, 0);
    venus.setStatus(12, 1);
  }
  venus.send();
}