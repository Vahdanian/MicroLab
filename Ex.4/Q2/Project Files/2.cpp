#include <stdio.h>
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

int counter = 0;
int hourValue = 0;
int minuteValue = 0;
int secondValue = 0;

#define LCD_Data_Dir DDRB      /* Define LCD data port direction */
#define LCD_Command_Dir DDRA   /* Define LCD command port direction register */
#define LCD_Data_Port PORTB    /* Define LCD data port */
#define LCD_Command_Port PORTA /* Define LCD data port */
#define RS PC0                 /* Define Register Select (data/command reg.)pin */
#define RW PC1                 /* Define Read/Write signal pin */
#define EN PC2                 /* Define Enable signal pin */

void timer_init()
{
    //prescaler set to clock/8 and overflow interrupt enabled
    TCCR2 |= 1 << CS21;
    TIMSK |= 1 << TOIE2;
    sei();
}

void LCD_Command(unsigned char cmnd)
{
    LCD_Data_Port = cmnd;
    LCD_Command_Port &= ~(1 << RS); /* RS=0 command reg. */
    LCD_Command_Port &= ~(1 << RW); /* RW=0 Write operation */
    LCD_Command_Port |= (1 << EN);  /* Enable pulse */
    _delay_us(1);
    LCD_Command_Port &= ~(1 << EN);
    _delay_ms(3);
}

void LCD_Init(void)
{
    LCD_Command_Dir = 0xFF; /* Make LCD command port direction as o/p */
    LCD_Data_Dir = 0xFF;    /* Make LCD data port direction as o/p */

    _delay_ms(20);     /* LCD Power ON delay always >15ms */
    LCD_Command(0x38); /* Initialization of 16X2 LCD in 8bit mode */
    LCD_Command(0x0C); /* Display ON Cursor OFF */
    LCD_Command(0x06); /* Auto Increment cursor */
    LCD_Command(0x01); /* clear display */
    LCD_Command(0x80); /* cursor at home position */
}

void LCD_Char(unsigned char char_data)
{
    LCD_Data_Port = char_data;
    LCD_Command_Port |= (1 << RS);
    LCD_Command_Port &= ~(1 << RW);
    LCD_Command_Port |= (1 << EN);
    _delay_us(1);
    LCD_Command_Port &= ~(1 << EN);
    _delay_ms(1);
}

void updateTime()
{
    secondValue += 1;
    if (secondValue == 60)
    {
        secondValue = 0;
        minuteValue += 1;
        if (minuteValue == 60)
        {
            minuteValue = 0;
            hourValue += 1;
            if (hourValue == 12)
            {
                hourValue = 0;
            }
        }
    }
    //Clear time and put pointer to first place
    LCD_Command(0x01);

    char clockText[40];
    sprintf(clockText, "%02d:%02d:%02d", hourValue, minuteValue, secondValue);
    for (int i = 0; clockText[i] != 0; i++)
    {
        LCD_Char(clockText[i]);
    }
}

ISR(TIMER2_OVF_vect)
{
    TCNT2 = 255- 125;
    counter += 1;
    if (counter % 1000 == 0)
    {
        counter = 0;
        updateTime();
    }
}

int main()
{
    LCD_Init();
    timer_init();

    while (1)
    {
    }

    return 0;
}