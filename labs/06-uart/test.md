# Lab 6: Anna Litovska

### ASCII

1. Complete the table with selected ASCII codes.

   | **Char** | **Decimal** | **Hexadecimal** | **Binary** |
   | :-: | :-: | :-: | :-: |
   | `a` | 97 | 0x61 | `0b0110_0001` |
   | `b` | 98 | 0x62 | `0b0110_0010` |
   | `c` | 99 | 0x63 | `0b0110_0011` |
   | `0` | 48 | 0x30 | `0b0011_0000` |
   | `1` | 49 | 0x31 | `0b0011_0001` |
   | `2` | 50 | 0x32 | `0b0011_0010` |
   | `Esc` | 27 | 0x1b | `0b0001_1011`  |
   | `Space` | 32 | 0x20 | `0b0010_0000` |
   | `Tab` | 9 | 0x9 | `0b0000_1001` |
   | `Backspace` |0x8 | 8 | `0b0000_1000` |
   | `Enter` | 13 | 0xd | `0b0000_1010` |

### UART communication

2. Draw a timing diagram of the output from UART/USART when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd). The image can be drawn on a computer (by [WaveDrom](https://wavedrom.com/) for example) or by hand. Name all parts of timing diagram.

   ![image](https://user-images.githubusercontent.com/99733524/200406801-539eb6dd-14c3-4c59-be04-389f0fc564dc.png)


3. Draw a flowchart for function `uint8_t get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear description of individual algorithm steps.
![image](https://user-images.githubusercontent.com/99733524/200347987-c0f2c8fc-038d-454e-a9e7-1da2a95861e6.png)


