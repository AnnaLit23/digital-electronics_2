# Lab 5: Anna Litovska

### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0 voltage** | **ADC value (calculated)** | **ADC value (measured)** | **ADC value (measured, hex)** |
   | :-: | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   | 0 | 0 |
   | Up     | 0.495&nbsp;V | 101 | 99 | 63 |
   | Down   | 1.203&nbsp;V | 246 | 256 | 100 |
   | Left   | 1.9697&nbsp;V | 403 | 409 | 199 |
   | Select | 3.1818&nbsp;V | 651 | 640 | 27f |
   | none   | 5&nbsp;V | 1023 | 1023 | 3ff |

### Temperature meter

Consider an application for temperature measurement. Use analog temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, and a LED. Every 30 seconds, the temperature is measured and the value is displayed on LCD screen. When the temperature is too high, the LED will turn on.

2. Draw a schematic of temperature meter. The image can be drawn on a computer or by hand. Always name all components, their values and pin names!

   ![image](https://user-images.githubusercontent.com/99733524/199113357-b2eeb3dc-cdd6-49a2-ae2f-c52fa0a3d807.png)


3. Draw two flowcharts for interrupt handler `TIMER1_OVF_vect` (which overflows every 1&nbsp;sec) and `ADC_vect`. The image can be drawn on a computer or by hand. Use clear descriptions of individual algorithm steps.

![image](https://user-images.githubusercontent.com/99733524/199113435-4a55d55e-4fd1-42ac-b3b7-e8376fff0bf5.png)
![image](https://user-images.githubusercontent.com/99733524/199113484-a0fec37f-0563-4ac1-837b-a3eaf0548aa8.png)


