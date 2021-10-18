#include <mega16.h>
#include <delay.h>

void main(void)
{

DDRA = 0x00;
PORTA = 0x00;

DDRB = 0xff;
PORTB = 0x00;


while (1)
      {
       if(PINA.0==0)
       { 
       PORTB.0 = 1;
       PORTB.1 = 1;
       PORTB.2 = 1;
       PORTB.3 = 1;
       PORTB.4 = 1;
       PORTB.5 = 1;
       PORTB.6 = 1;
       PORTB.7 = 1;
       
       delay_ms(500); 
       
       PORTB.0 = 0;
       PORTB.1 = 0;
       PORTB.2 = 0;
       PORTB.3 = 0;
       PORTB.4 = 0;
       PORTB.5 = 0;
       PORTB.6 = 0;
       PORTB.7 = 0;
       
       delay_ms(500);
        }
      }
}
