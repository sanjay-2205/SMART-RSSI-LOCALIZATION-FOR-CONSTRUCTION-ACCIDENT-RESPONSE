#ifndef RESP_H
#define RESP_H 
#include "global.h"
int r;
int count6;
int avg;
void Resp(void)
{
        for (int i = 0; i < 20; i++)
        {
          lcd.clear();
          lcd.setCursor(12, 0);
          lcd.print(i);
          r = digitalRead(res);
           Serial.println(r);
          if (r == 0)
          {
            count6++;
            lcd.setCursor(12, 1);
            lcd.print(count6);
            //Serial.println(count6);
          }
          delay(1000);
        }
        avg = (count6 * 3);
//        lcd.setCursor(0, 1);
//        lcd.print("RESP:");
//        lcd.print(avg);
        //Serial.println("RESP:");
        Serial.print(avg);
        count6 = 0;
        delay(1000);
      }
#endif
