# Lab 1: Anna Litovska

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c
void setup()
{
    // Set pin where on-board LED is connected as output
    pinMode(LED_GREEN, OUTPUT);
}
    // Infinite loop
    void loop()
    {
        digitalWrite (LED_GREEN, HIGH);
        _delay_ms(SHORT_DELAY);
        digitalWrite (LED_GREEN, LOW);
        _delay_ms(SHORT_DELAY);      
        digitalWrite (LED_GREEN, HIGH);
        _delay_ms(3*SHORT_DELAY);
        digitalWrite (LED_GREEN, LOW);
        _delay_ms(SHORT_DELAY);      

       

    }

   

```

2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

![image](https://user-images.githubusercontent.com/99733524/193671862-49dc3366-7abb-40aa-ac04-f59249fc142f.png)



