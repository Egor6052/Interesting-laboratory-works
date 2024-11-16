Компілюємо:
```
avr-gcc -mmcu=atmega8 -DF_CPU=16000000UL -Os -o main.o main.c
```
тут: 
led.o - файл, який ми отримаємо;
led.c - файл, який ми написали;

Додаємо в hex:
```
avr-objcopy -O ihex -R .eeprom main.o main.hex
```
тут: 
led.o - файл, який ми отримали;
led.c - файл, який ми хочемо створити для прошивки;

Прошиваємо контролер:
```
avrdude -c usbasp -p m8 -U flash:w:main.hex
```
Де: 
m8 - тип контролера (Atmega8);
led.hex - файл з кодом;