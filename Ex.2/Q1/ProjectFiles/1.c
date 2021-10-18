#include <mega16.h>
#include <delay.h>

void main(void)
{

DDRA=0xff;
PORTA=0x00;


while (1)
      {
      PORTA.0=!PORTA.0;
      delay_ms(500);

      }
}
