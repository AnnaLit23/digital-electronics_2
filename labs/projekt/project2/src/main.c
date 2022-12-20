/***********************************************************************
 * 
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 * 
 *


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <stdlib.h>         // C library. Needed for number conversions

/* Define pins  ------------------------------------------*/
#define servo1 PB1           // Motor 1

#define servo2 PB2           // Motor 2

#define BUTTON1 PB0          // Button 1



/* Define parameters for servo ---------------------------------------------------------*/
# define ANGLE_ZERO 124
# define ANGLE_180 260
# define SHORT_DELAY 2000 // Delay in milliseconds

volatile uint32_t servo1_position = ANGLE_180;
volatile uint32_t servo2_position = ANGLE_180;
volatile uint8_t RUN = 0;

int main(void)
{
    /* ----------------------------- Timer for SERVO 1 ---------------------------------*/
    TIM0_overflow_16ms();
    TIM0_overflow_interrupt_enable();

    /* ------------------------- Set pins with gpio library ----------------------------*/
    GPIO_mode_output(&DDRB, servo1);        // 1. servo motor
    GPIO_mode_output(&DDRB, servo2);        // 2. servo motor
    GPIO_mode_input_pullup(&DDRB,BUTTON1);  // set Button with enabled pull-up resistor

    // Set generation mode 
    TCCR1A |= (1 << WGM11);                  
    TCCR1B |= (1 << WGM13);

    // Set compare output
    TCCR1A |= (1 << COM0A1) | (1 << COM0B1); 

     // Set TOP value
    ICR1 = 2500;
    
                         
    // Set duty cycle
    OCR1A = servo1_position;
    OCR1B = servo2_position;
    
    // Prescaler to 64
    TCCR1B |= (1 << CS11) | (1 << CS10 ); 

    PCICR |= (1<<PCIE0);                    // Interruotion due to changes in any enable PCINT [7:0] pins
    PCMSK0 |= (1<<PCINT0);                  // Enable PCINT0 change interrupt  
    _delay_ms(SHORT_DELAY); // Wait 2 s

    // Enables interrupts by setting the global interrupt mask
    sei();
    
    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;

}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/1 overflow interrupt
 * Purpose:  Use single conversion mode and start conversion every 33 ms.
 **********************************************************************/

ISR(TIMER0_OVF_vect)
{
    static uint8_t servo1_direction = 0;        // Default direction setup for first servo motor
    static uint8_t servo2_direction = 0;        // Default direction setup for second servo motor
    /* ------------- First servo motor  ------------------------------*/
    if (RUN == 0)                                                      
    {
        // Direction for servo 1
        if (servo1_position == ANGLE_180)       // Maximum value
            {
                servo1_direction = 1;           // Clockwise direction
            }
        else if (servo1_position == ANGLE_ZERO) // Minimum value
            {
                servo1_direction = 0;           // Counterclockwise direction
            }
        // Motion for servo 1
        if (servo1_direction == 0)
        {
            servo1_position += 4;               // Increment variable 
        }
        if (servo1_direction == 1)
        {
            servo1_position -= 4;               // Decrement variable  
        }
        OCR1A = servo1_position;                // Put value from variable into arduino register

         // Direction for servo 2
        if (servo2_position == ANGLE_180)       // Maximum value
        {
            servo2_direction = 1;               // Clockwise direction
        }
        else if (servo2_position == ANGLE_ZERO) // Minimum value
        {
            servo2_direction = 0;               // Counterclockwise direction
        }
        // Motion for servo 2
        if (servo2_direction == 0)
        {
            servo2_position += 2;               // Increment variable 
        }
        if (servo2_direction == 1)
        {
            servo2_position -= 2;               // Decrement variable   
        }
        OCR1B = servo2_position;                // Put value from variable into arduino register
        }
    

}
/**********************************************************************
 * Function: Pin PB0 change interrupt
 * Purpose:  Determines whether the motors should move.
 **********************************************************************/

ISR(PCINT0_vect)
{
    uint8_t sw1 = GPIO_read(&PINB, BUTTON1);     // Read value from digital pin 8
    if (sw1 == 0)                              // Button is pushed down  
    {
        if (RUN == 1) 
        { 
            RUN = 0;                            
        }
        else if (RUN == 0) 
        { 
            RUN = 1;
        }
    } 
}
