# Project 1

Application of analog joy-stick (2 ADC channels, 1 push button), rotary encoder, and Digilent PmodCLP LCD module.



## GitHub repository structure

   ```c
   PROJECT        // PlatfomIO project
   ├── include
   │  └── timer.h       
   ├── lib             // Libraries
   │  └── gpio
   │       └── gpio.c
   │       └── gpio.h
   │   └── lcd
   │        └── lcd.definitions.h
   │        └── lcd.h
   │        └── lcd.c
   ├── src             // Source file(s)
   │   └── main.c
   └── platformio.ini  // Project Configuration File
   ```

### Team members

* Maksim Migulia (233261)
* Anna Litovska (231581)

## Hardware description

### Joy-stick

* GND to GND 
* +5V to +5V
* Vrx and Vry we connect to analog pins A0, A1 

### Digilent PmodCLP LCD modul 

* GND to GND 
* VCC to +5V J2
* pins 7,10 to digital pins 4, 7
* RW to GND
* Rs and En to digital pins 8 and 9

### Rotation encoder

* GND to GND
* +5V to +5V
* CLK and DT to digital pins 11, 12
* SW to digital pin 2

![image](https://user-images.githubusercontent.com/99403646/205863718-c15f8ad5-0dea-43c7-92e9-262a9b21254c.png)

Obr. 1 - Schéma zapojení v SimulIDE

![image](https://user-images.githubusercontent.com/99403646/205864286-3a4a17cd-4702-49ea-a2d2-6c1e31e3c709.png)

Obr. 2 - Schéma reálného zapojení 


## Software description

![image](https://user-images.githubusercontent.com/99403646/205865422-d6dad741-c66c-4e6f-b598-7912b6b96adf.png)

![image](https://user-images.githubusercontent.com/99403646/205865529-51586952-727d-4822-bb06-3401c3559a8b.png)

## Video
https://youtu.be/-JzXT4BKrfg

## Reference

1. https://www.c-sharpcorner.com/article/how-to-connect-arduino-joystick-in-arduino-uno/

