#include <Arduino.h>

#include <lcd2004.h>

// 8 bit mode
// RS, E, D0, D1, D2, D3, D4, D5, D6, D7, Width, Height
Lcd2004 lcd(3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 16, 2);
// 4 bit mode
// RS, E, D4, D5, D6, D7, Width, Height
// Lcd2004 lcd(2, 3, 4, 5, 6, 7, 16, 2);

void setup()
{
    // Fonts: LCD_FONT_5X8, LCD_FONT_5X10
    lcd.init(LCD_FONT_5X8);

    // Очистка (Происходит внутри init)
    // lcd.clear();

    // Возврат домой (Происходит внутри init)
    // lcd.returnHome();

    // Свои символы
    uint8_t symbol[8] = {
        0b00000, // _____
        0b01010, // _x_x_
        0b01010, // _x_x_
        0b01010, // _x_x_
        0b00000, // _____
        0b10001, // x___x
        0b01110, // _xxx_
        0b00000, // _____
    };
    // Первое число это id, от 0 до 7 включительно, но для удобства лучше от 1 до 7 включительно
    lcd.saveCustomChar(1, symbol);

    // Изменение состояния курсора, по умолчанию курсор выкл.
    // 1: Включить курсор? 2: Включить мигание курсора?
    lcd.setCursor(true, true);

    // Изменение состояния экрана, по умолчания дисплей вкл.
    lcd.setOn(true);
}
int counter = 0;

void loop()
{
    // Очистка, позиция установлена в 0, 0
    lcd.clear();

    // Установка позиции (x, y), после init стоит 0, 0
    lcd.setPosition(0, 1);

    // Доступны все методы класса Print
    lcd.printf("Hello, World! %d", counter);

    // Вместо lcd.setPosition лучше использовать returnHome
    lcd.returnHome();

    // Вывод добавленых ранее символов, таким способом можно вывести все кроме нулевого символа
    lcd.print("\1 <- custom char");

    // Вывод своего символа
    // lcd.write(0);

    counter++;
    delay(1000);
}
