#ifndef IOT_H
#define IOT_H

void send_iot(String s)
{
  for(int i=0; i<s.length(); i++)
  {
    Serial.write(s[i]);
  }
  delay(1000);
}
#endif
