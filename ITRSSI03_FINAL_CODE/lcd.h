#ifndef LCD_H
#define LCD_H

#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

void NEAR_LCD()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PERSON LOCATED");
  lcd.setCursor(0,1);
  lcd.print("5 MTS AWAY");
}
void FAR_LCD()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PERSON LOCATED");
  lcd.setCursor(0,1);
  lcd.print("10 MTS AWAY");
}
void TOOFAR_LCD()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PERSON LOCATED");
  lcd.setCursor(0,1);
  lcd.print("20 MTS AWAY");
}
#endif
