#include <avr/io.h>
#include <util/delay.h>

// Піни дисплея
#define RST PC5
#define DC  PC4
#define CS  PB2
#define MOSI PB3
#define SCK PB5

// Пін для мотора
#define MOTOR_PIN PC0

// Команди дисплея
#define LCD_COMMAND 0
#define LCD_DATA    1

// Ініціалізація SPI
void SPI_init(void) {
    // MOSI, SCK, CS як виходи, SS як вихід (PB2)
    DDRB |= (1 << MOSI) | (1 << SCK) | (1 << CS) | (1 << PB2);
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // SPI увімкнено, Master, частота знижена
}

// Відправка байта через SPI
void SPI_send(uint8_t data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF))); // Очікуємо завершення передачі
}

// Відправка команди або даних на дисплей
void LCD_send(uint8_t data, uint8_t mode) {
    if (mode == LCD_COMMAND) {
        PORTC &= ~(1 << DC);
    } else {
        PORTC |= (1 << DC);
    }
    PORTB &= ~(1 << CS);
    SPI_send(data);
    PORTB |= (1 << CS);
}

// Ініціалізація дисплея Nokia 5110
void LCD_init(void) {
    DDRC |= (1 << RST) | (1 << DC);
    PORTC &= ~(1 << RST);
    _delay_ms(10);
    PORTC |= (1 << RST);

    LCD_send(0x21, LCD_COMMAND);
    LCD_send(0xB1, LCD_COMMAND);
    LCD_send(0x04, LCD_COMMAND);
    LCD_send(0x14, LCD_COMMAND);
    LCD_send(0x20, LCD_COMMAND);
    LCD_send(0x0C, LCD_COMMAND);
}

// Очищення дисплея
void LCD_clear(void) {
    for (uint16_t i = 0; i < 504; i++) {
        LCD_send(0x00, LCD_DATA);
    }
}

// Встановлення курсора
void LCD_setCursor(uint8_t x, uint8_t y) {
    LCD_send(0x80 | x, LCD_COMMAND);
    LCD_send(0x40 | y, LCD_COMMAND);
}

// Таблиця ASCII символів (частково, для прикладу)
const uint8_t ASCII[][5] = {
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x5F, 0x00, 0x5F, 0x00, 0x00},
    {0x24, 0x7E, 0x24, 0x7E, 0x24},
    {0x7C, 0x12, 0x11, 0x12, 0x7C},
    {0x38, 0x54, 0x54, 0x54, 0x18},
    {0x38, 0x54, 0x54, 0x54, 0x18},
    {0x3C, 0x42, 0x42, 0x42, 0x3C},
};


void LCD_drawChar(char c) {
    for (uint8_t i = 0; i < 5; i++) {
        LCD_send(ASCII[c - ' '][i], LCD_DATA);
    }
    LCD_send(0x00, LCD_DATA);
}

void LCD_drawString(const char* str) {
    while (*str) {
        LCD_drawChar(*str++);
    }
}

// Ініціалізація мотора
void Motor_init(void) {
    DDRC |= (1 << MOTOR_PIN);
    PORTC &= ~(1 << MOTOR_PIN);
}

// Увімкнути/вимкнути мотор
void Motor_toggle(void) {
    PORTC ^= (1 << MOTOR_PIN);
}

// Основна функція
int main(void) {
    SPI_init();
    LCD_init();
    LCD_clear()
    Motor_init();

    LCD_setCursor(0, 0);
    LCD_drawString("HELLO");

    while (1) {
        Motor_toggle();
        _delay_ms(1000);
    }
}
