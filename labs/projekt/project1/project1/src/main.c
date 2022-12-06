


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions

int position;
int x;
int y;

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and start ADC conversion every 100 ms.
 *           When AD conversion ends, send converted value to LCD screen.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize display
    lcd_init(LCD_DISP_ON);
    lcd_gotoxy(1, 0); lcd_puts("joy:");
    lcd_gotoxy(1, 1); lcd_puts("encoder:");
    lcd_gotoxy(6, 0); lcd_puts("0");
      // Put ADC value in decimal
    lcd_gotoxy(9,1); lcd_puts("0");  // Put ADC value in hexadecimal
   // lcd_gotoxy(8, 1); lcd_puts("c");  // Put button name here

    // Configure Analog-to-Digital Convertion unit
    // Select ADC voltage reference to "AVcc with external capacitor at AREF pin"
     ADMUX = ADMUX | (1<<REFS0);

    // Select input channel ADC0 (voltage divider pin)

     ADMUX = ADMUX & ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1)| (1<<MUX0));
     //ADMUX |= (1<<MUX0);
     
    // Enable ADC module
     ADCSRA |= (1<<ADEN);
    // Enable conversion complete interrupt
    ADCSRA |= (1<<ADIE);
    // Set clock prescaler to 128
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);


    // Configure 16-bit Timer/Counter1 to start ADC conversion
    TIM1_overflow_262ms();
    TIM1_overflow_interrupt_enable();

    // Set prescaler to 33 ms and enable overflow interrupt


    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Use single conversion mode and start conversion every 100 ms.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // Start ADC conversion
    if (position == 0)
    {
      ADMUX |= (1<<MUX0);
      ADCSRA |= (1<<ADSC);
       y = ADC;
    }
    else
    {
      ADMUX = ADMUX &= ~ (1<<MUX0);
      ADCSRA |= (1<<ADSC);
      x = ADC;


    }

}

/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display converted value on LCD screen.
 **********************************************************************/
ISR(ADC_vect)
{
    
   
    uint16_t value;
    char string[4];  // String for converted numbers by itoa()

    // Read converted value
    // Note that, register pair ADCH and ADCL can be read as a 16-bit value ADC
    
    // Convert "value" to "string" and display it

    itoa (x, string, 10);
    lcd_gotoxy(6,0);
    lcd_puts("    ");
    lcd_gotoxy(6,0);
    lcd_puts(string);


    
    lcd_gotoxy(10, 0);
    if (x >530 )
    {
     lcd_gotoxy(10, 0);
     lcd_puts("right");
    }
    else if (x < 100)
    {
      lcd_gotoxy(10, 0);
      lcd_puts("left ");
    }

   lcd_gotoxy(10, 0);
    if (y >530 )
      lcd_puts("up   ");
    else if (y < 100)
      lcd_puts("down ");

      if (position == 0)
      position = 1;
      else
      position = 0;

}
