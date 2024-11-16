#include <avr/io.h>
#include <util/delay.h>

// Піни дисплея
#define SCE  PB0  // Chip Enable (CS)
#define RST  PB1  // Reset
#define DC   PB2  // Data/Command
#define SCLK PB5  // Clock
#define MOSI PB3  // Data In (MOSI)

// Команди дисплея
#define LCD_COMMAND 0
#define LCD_DATA    1

// Ініціалізація SPI
void SPI_init(void) {
    DDRB |= (1 << MOSI) | (1 << SCLK) | (1 << SCE) | (1 << DC);  // Установити піни як виходи
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // SPI режим
}

// Відправка байта через SPI
void SPI_send(uint8_t data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));  // Очікуємо завершення передачі
}

// Відправка команди або даних на дисплей
void LCD_send(uint8_t data, uint8_t mode) {
    if (mode == LCD_COMMAND) {
        PORTB &= ~(1 << DC);  // Встановлюємо режим команди
    } else {
        PORTB |= (1 << DC);   // Встановлюємо режим даних
    }
    PORTB &= ~(1 << SCE);  // Активуємо CS (SCE)
    SPI_send(data);
    PORTB |= (1 << SCE);   // Деактивуємо CS (SCE)
}

// Ініціалізація дисплея Nokia 1100
void LCD_init(void) {
    DDRB |= (1 << RST) | (1 << DC) | (1 << SCE);  // Піни як виходи

    PORTB &= ~(1 << RST);   // Скидаємо дисплей
    _delay_ms(10);
    PORTB |= (1 << RST);    // Відновлюємо дисплей

    LCD_send(0x21, LCD_COMMAND);  // Включення розширеного режиму
    LCD_send(0xC0, LCD_COMMAND);  // Налаштування контрасту
    LCD_send(0x04, LCD_COMMAND);  // Температурний коефіцієнт
    LCD_send(0x14, LCD_COMMAND);  // Налаштування Vop
    LCD_send(0x20, LCD_COMMAND);  // Вимкнення розширеного режиму
    LCD_send(0x0C, LCD_COMMAND);  // Включення дисплея
}

// Очищення дисплея
void LCD_clear(void) {
    for (uint16_t i = 0; i < 504; i++) {
        LCD_send(0x00, LCD_DATA);  // Відправка нулів для очищення
    }
}

// Заповнення екрану прямокутником
void LCD_drawRect(void) {
    for (uint8_t y = 0; y < 6; y++) {
        LCD_send(0x80, LCD_COMMAND);  // Встановити курсор на перший стовпчик
        LCD_send(0x40 | y, LCD_COMMAND);  // Встановити рядок
        for (uint8_t x = 0; x < 84; x++) {
            LCD_send(0xFF, LCD_DATA);  // Заповнити екран
        }
    }
}

// Основна функція
int main(void) {
    SPI_init();  // Ініціалізація SPI
    LCD_init();  // Ініціалізація дисплея
    LCD_clear(); // Очищення дисплея

    while (1) {
        LCD_drawRect();  // Виведення прямокутника
        _delay_ms(1000); // Затримка 1 секунда
        LCD_clear();     // Очистити дисплей
        _delay_ms(1000); // Затримка 1 секунда
    }
}
