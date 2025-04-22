#include <avr/io.h>

int main(void) {
    DDRB |= (1 << PB0);   // Set PB0 (OC0B) as output

    // Configure Timer0 for Fast PWM mode with TOP=OCR0A
    TCCR0A = (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
    TCCR0B = (1 << WGM02) | (1 << CS02) | (0 << CS01) | (1 << CS00);

    OCR0A = 155;  // Set TOP value for ~50Hz frequency
    OCR0B = 77;   // 50% duty cycle (half of OCR0A + 1)

    while (1) {}  // Keep the program running
}
