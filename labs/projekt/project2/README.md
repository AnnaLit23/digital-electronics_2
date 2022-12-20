# Project 2


### Team members

* Maksim Migulia (responsible for coding and dokumentation)
* Anna Litovska (responsible for coding and dokumentation)

## Hardware description

![image](https://user-images.githubusercontent.com/99733524/208757709-5d0bda7b-2c37-4e3d-a44a-6fef050c36b1.png)

Picture 1 Wiring diagram

### First Servo motor SG90

* GND to GND

* V+ to +5V

* SIG to digital pin 9

### Second Servo motor SG90

* GND to GND

* V+ to +5V

* SIG to digital pin 10

### Button

* GND to GND 

* +5V to +5V

* SW to digital pin 8 

## Software description
### Structure

   ```c
   project2        // PlatfomIO project
   ├── include         // Included files
   │   └── timer.h
   ├── lib             // Libraries
   │   └── gpio
   │       └── gpio.h
   │       └── gpio.c
   ├── src             // Source file(s)
   │   └── main.c
   ├── test            // No need this
   ├── platformio.ini  // Project Configuration File
   └── README.md       // Report of this project
   ```
   
Links:

  include: [timer.h](https://github.com/AnnaLit23/digital-electronics_2/blob/main/labs/projekt/project2/include/timer.h)
   
  lib - gpio: 
   [gpio.h](https://github.com/AnnaLit23/digital-electronics_2/blob/main/labs/projekt/project2/lib/gpio/gpio.h),
   [gpio.c](https://github.com/AnnaLit23/digital-electronics_2/blob/main/labs/projekt/project2/lib/gpio/gpio.c)
   
  src: [main.c](https://github.com/AnnaLit23/digital-electronics_2/blob/main/labs/projekt/project2/src/main.c)
  
  In gpio we are setting pins and reading their value. Timer we are using for PWM
  
  
  ![image](https://user-images.githubusercontent.com/99733524/208750713-e27dd5c7-2236-4006-bbf3-234f3c720e3c.png)
  
  Picture 2 Flowchat of main
  
  ![image](https://user-images.githubusercontent.com/99733524/208750954-d26ceec4-5bff-4905-aae5-1c5c38c64a8b.png)

  Picture 3 Flowchat of TIMER1_ovf_vect (moving Servo Motors)
  
  In TIMER1_ovf_vect we set the PWM signal generation so that the SG90 Servo Motors move simultaneously. The 10th mod is used under the technical sheet.
   
  ![image](https://user-images.githubusercontent.com/99733524/208751035-0f2253c4-6ebb-471b-89ce-393cad97ad76.png)
  
  Picture 4 Flowchat of PCINTO_vect (switching the Button)
  
  PCINT0_vect determines whether the motors should move ( we are change the value of RUN, depending on the button pressed)


## Video

https://youtube.com/shorts/Sxfhcp9AFbQ?feature=share

## References

1.  [doc. Ing. Tomáš Frýza, Ph.D "digital-electronics-2"](https://github.com/tomas-fryza/digital-electronics-2)

2. https://automaticaddison.com/how-to-control-multiple-servo-motors-using-arduino/

3. https://how2electronics.com/how-to-control-multiple-servo-motors-with-arduino/
