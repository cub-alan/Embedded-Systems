#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 
int x = 0;
DigitalOut red(TRAF_RED1_PIN,1);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

//Object for controlling the LCD
LCD_16X2_DISPLAY lcd;

int main()
{
    while(true)
    {
     red = 1;
     lcd.puts("RED");
     wait_us(10000000);

     amber = 1;
      lcd.cls();
      lcd.puts("Amber");
     wait_us(2000000);

      red = 0;
     amber = 0;

      green = 1;
      lcd.cls();
      lcd.puts("Green");    
     wait_us(10000000);
      green = 0;
     x = 0;
    while (x < 4)
    {
        x=x+1;
        amber = 1;
        wait_us(250000);
        amber = 0;
        wait_us(250000);
    }
     lcd.cls();
     lcd.puts("TASK-104");
    }
}