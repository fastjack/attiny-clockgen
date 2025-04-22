#include <avr/io.h>

// Define OCR0A values and prescaler based on CKDIV8
#ifdef CKDIV8
  // 1MHz clock settings
  #define PRESCALER_BITS ((1 << CS01) | (1 << CS00))  // Prescaler = 64
  #define OCR0A_50HZ     155  // 50Hz: 1MHz / (2*64*(155+1)) ≈ 50.08Hz
  #define OCR0A_60HZ     129  // 60Hz: 1MHz / (2*64*(129+1)) ≈ 60.1Hz
#else
  // 8MHz clock settings (default)
  #define PRESCALER_BITS ((1 << CS02) | (1 << CS00))  // Prescaler = 1024
  #define OCR0A_50HZ     77   // 50Hz: 8MHz / (2*1024*(77+1)) ≈ 50.08Hz
  #define OCR0A_60HZ     64   // 60Hz: 8MHz / (2*1024*(64+1)) ≈ 60.14Hz
#endif

int main(void) {
    DDRB |= (1 << PB0);    // PB0 (OC0A) as output
    DDRB &= ~(1 << PB1);   // PB1 as input
    PORTB |= (1 << PB1);   // Enable pull-up on PB1

    // Configure Timer0 for CTC mode (toggle OC0A on compare match)
    TCCR0A = (1 << COM0A0) | (1 << WGM01);  // Toggle OC0A, CTC mode
    TCCR0B = PRESCALER_BITS;  // Set prescaler (64 or 1024)

    // Set OCR0A based on PB1 state
    if (PINB & (1 << PB1)) {  // PB1 HIGH → 50Hz
        OCR0A = OCR0A_50HZ;
    } else {                  // PB1 LOW → 60Hz
        OCR0A = OCR0A_60HZ;
    }

    while (1) { }
}
