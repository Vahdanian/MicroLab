#include <mega16.h>
#include <delay.h>

void main(void)
{

DDRA=0x00;
PORTA=0x00;
DDRB=0xff;
PORTB=0x00;


while (1)
      {
      if(PINA.0==0)
       {
       PORTB.0=1;
       delay_ms(200);
       PORTB.1=1;
       PORTB.0=0;
       }
      
       if(PORTB.1==1)
       {
       delay_ms(200);
       PORTB.2=1;
       PORTB.1=0;
       }
      
      if(PORTB.2==1)
       {
       delay_ms(200);
       PORTB.3=1;
       PORTB.2=0;
       }
       
       if(PORTB.3==1)
       {
       delay_ms(200);
       PORTB.4=1;
       PORTB.3=0;
       } 
       
       if(PORTB.4==1)
       {
       delay_ms(200);
       PORTB.5=1;
       PORTB.4=0;
       } 
       
       if(PORTB.5==1)
       {
       delay_ms(200);
       PORTB.6=1;
       PORTB.5=0;
       } 
       
       if(PORTB.6==1)
       {
       delay_ms(200);
       PORTB.7=1;
       PORTB.6=0;
       }  
       
       if(PORTB.7==1 && PORTB.6==0)
       {
       delay_ms(200);
       PORTB.6=1;
       PORTB.7=0;
       }  
       
        if(PORTB.6==1 && PORTB.5==0)
       {
       delay_ms(200);
       PORTB.5=1;
       PORTB.6=0;
       }   
       
        if(PORTB.5==1 && PORTB.4==0)
       {
       delay_ms(200);
       PORTB.4=1;
       PORTB.5=0;
       } 
       
        if(PORTB.4==1 && PORTB.3==0)
       {
       delay_ms(200);
       PORTB.3=1;
       PORTB.4=0;
       }
       
        if(PORTB.3==1 && PORTB.2==0)
       {
       delay_ms(200);
       PORTB.2=1;
       PORTB.3=0;
       }  
       
        if(PORTB.2==1 && PORTB.1==0)
       {
       delay_ms(200);
       PORTB.1=1;
       PORTB.2=0;
       } 
       
        if(PORTB.1==1 && PORTB.0==0)
       {
       delay_ms(200);
       PORTB.0=1;
       PORTB.1=0; 
       delay_ms(200);
       PORTB.0=0;
       }
        
      }
}
