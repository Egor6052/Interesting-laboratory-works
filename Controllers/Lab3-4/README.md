Компілюємо:
```
avr-gcc -mmcu=atmega8 -DF_CPU=16000000UL -Os -o main.o main.c
```
тут: 
main.o - файл, який ми отримаємо;
main.c - файл, який ми написали;

Додаємо в hex:
```
avr-objcopy -O ihex -R .eeprom main.o main.hex
```
тут: 
main.o - файл, який ми отримали;
main.c - файл, який ми хочемо створити для прошивки;

Прошиваємо контролер:
```
avrdude -c usbasp -p m8 -U flash:w:main.hex
```
Де: 
m8 - тип контролера (Atmega8);
main.hex - файл з кодом;