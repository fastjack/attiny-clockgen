ATtiny 

This tiny program will generate a 50Hz signal. This is intended to be an alternative to https://github.com/ytmytm/c128-link232?tab=readme-ov-file#attiny85

While the ini file is set up for an ATtiny85 the program is short enough to be flashed onto an ATtiny45 or even ATtiny25.

Calculations:
- Frequency:
$$ f = \frac{8 \text{ MHz}}{1024 \times (155 + 1)} \approx 50.08 \text{ Hz} $$

- Duty Cycle:
$$ \text{Duty} = \frac{\text{OCR0B} + 1}{\text{OCR0A} + 1} = \frac{78}{156} = 50\% $$

Connections:
 - PB0 (Pin 5)
 : Outputs the 50Hz PWM signal
