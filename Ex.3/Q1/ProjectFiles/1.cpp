#include <avr/io.h>
#include <avr/interrupt.h>

int LED_Value = 0;

void initTimer(){
    TCNT1 = 0;
    //unmask the interrupt and use prescaler and finnaly enable interrupt
    TIMSK |= (1 << TOIE1);
    TCCR1B |= (1 << CS11); 
    sei();
}

int main()
{
    //Setting c and D ports for output
    DDRC |= 0b0000001;
    DDRD |= 0b1111111;
    //activate and initialize the seven-segment
    PORTC = 0b0000000;
    PORTD = 0b0111111;
    initTimer();
    while (1);
    return 0;
}

ISR(TIMER1_OVF_vect)
{
    PORTD = 0;
    if (LED_Value == 10)
    {
       LED_Value =0;
    }
    if (LED_Value == 0)
    {
       PORTD= 0b0111111;
    }else if (LED_Value == 1)
    {
       PORTD = 0b0000110;
    }
    else if (LED_Value == 2)
    {
       PORTD = 0b1011011;
    }
    else if (LED_Value == 3)
    {
       PORTD = 0b1001111;
    }else if (LED_Value == 4)
    {
       PORTD = 0b1100110;
    }else if (LED_Value == 5)
    {
       PORTD = 0b1101101;
    }else if (LED_Value == 6)
    {
       PORTD = 0b1111101;
    }else if (LED_Value == 7)
    {
       PORTD = 0b0000111;
    }else if (LED_Value == 8)
    {
       PORTD = 0b1111111;
    }else if (LED_Value == 9)
    {
       PORTD = 0b1101111;
    }
      LED_Value+=1;
    TCNT1 = 0; 
}

