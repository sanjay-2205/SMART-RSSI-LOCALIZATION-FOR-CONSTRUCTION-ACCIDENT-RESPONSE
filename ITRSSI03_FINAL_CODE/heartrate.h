#ifndef HEARTRATE_H
#define HEARTRATE_H
#include"global.h"


void heart(void)
{
  int j = 120;
  int i = 0;
  while (j > 0)
  {
    if (digitalRead(HEART_PIN) == LOW)
      i++;
    j--;
    delay(14);
  }
  heart_rate = i;
  
 
}

#endif
