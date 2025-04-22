# Clock generator

This tiny program generates a 50Hz/60Hz clock signal. This is intended to be an alternative to https://github.com/ytmytm/c128-link232?tab=readme-ov-file#attiny85

## Calculations:

### CTC Frequency Formula

$$ f = \frac{f_{CPU}}{2 \times \text{prescaler} \times (\text{OCR0A} + 1)} $$

### For 50 Hz @ 1 MHz (PB1 HIGH):

$$ \text{OCR0A} = \frac{1 \text{ MHz}}{2 \times 64 \times 50} - 1 = 155 $$
Actual: 50.08 Hz \[+0.16%\]

### For 60 Hz @ 1 MHz (PB1 LOW):
$$ \text{OCR0A} = \frac{1 \text{ MHz}}{2 \times 64 \times 60} -1 = 129 $$
Actual: 60.1 Hz \[+0.17%\]

## Timer/Prescaler values
| Parameter | 8 MHz Clock | 1 MHz Clock |
| -- | -- | -- |
| Prescaler | 1024 | 64 |
| OCR0A (50 Hz) | 77 | 155 |
| OCR0A (60 Hz) | 64 | 129 |
| Accuracy | ±0.1% | ±0.17% |


## Connections
 - PB0 (Pin 5)
 : Outputs the 50 Hz or 60 Hz clock signal
 - PB1 (Pin 6)
 : Input, selects 50 Hz (HIGH) / 60 Hz (LOW)
