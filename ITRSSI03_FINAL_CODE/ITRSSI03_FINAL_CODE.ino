#include "global.h"
//#include "gps.h"
#include "heartrate.h"
#include "iot.h"
#include "lcd.h"
#include "resp.h"

void setup() {
  Serial.begin(9600);
  //mySerial.begin(9600);
  lcd.begin(16, 2);
  pinMode(BUZZER, OUTPUT);
  pinMode(HEART_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  //pinMode(gps_enable, INPUT_PULLUP);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Construction");
  lcd.setCursor(0, 1);
  lcd.print("area rescue");
  delay(2000);
}

void loop() {

  //dht.dht_read(7);
  //temp = (dht.temperature * (9.0 / 5.0)) + 32;
  avg = 0;
  heart_rate = 0;
  heart();
  send_iot("*" + String(heart_rate) + "#");
  if (heart_rate != 0 && heart_rate != 120)
  {
    Resp();
    send_iot("@" + String(avg) + "#");
  }
  if ((heart_rate < 60 || heart_rate > 100) && heart_rate!=0 && heart_rate!=120)
  {
    send_iot("&Heartrate abnormal#");
    digitalWrite(BUZZER, HIGH);
    delay(2000);
    digitalWrite(BUZZER, LOW);
  }
  if ((avg < 12 || avg > 16) && avg!=0)
  {
    send_iot("&Respiration abnormal#");
    digitalWrite(BUZZER, HIGH);
    delay(2000);
    digitalWrite(BUZZER, LOW);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HR:");
  lcd.print(heart_rate);
  lcd.print(" RESP:");
  lcd.print(avg);
  delay(1000);
}
void serialEvent(void)
{
  if (Serial.available() > 0)
  {
    char inchar = Serial.read();
    switch (inchar)
    {
      case 'A':
        send_iot("&Detected within around 5 meters#");
        //send_iot("*LAT:" + String(lati) + "LON:" + String(longi) + "#");
        NEAR_LCD();
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(BUZZER, HIGH);
        delay(2000);
        digitalWrite(BUZZER, LOW);
        break;
      case 'B':
        send_iot("&Detected within around 10 meters#");
        //send_iot("*LAT:" + String(lati) + "LON:" + String(longi) + "#");
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BUZZER, LOW);
        FAR_LCD();
        break;
      case 'C':
        send_iot("&Detected within around 20 meters#");
        //send_iot("*LAT:" + String(lati) + "LON:" + String(longi) + "#");
        digitalWrite(RED_LED, HIGH);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BUZZER, LOW);
        TOOFAR_LCD();
        break;
    }
  }
}
