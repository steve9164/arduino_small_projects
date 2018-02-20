// Control 2 common anode 7-segment digits with one shift register, one bank of 8 resistors
// and 2 PNP transistors installed between 5V and the anodes of the 7-segments

// Shift register pins
#define LATCH (6)
#define DATA  (4)
#define CLOCK (5)
#define TR1   (7)
#define TR2   (8)

// Inverted (use with common anode 7-segment)
#define ZERO    (0b00000011)
#define ONE     (0b10011111)
#define TWO     (0b00100101)
#define THREE   (0b00001101)
#define FOUR    (0b10011001)
#define FIVE    (0b01001001)
#define SIX     (0b01000001)
#define SEVEN   (0b00011111)
#define EIGHT   (0b00000001)
#define NINE    (0b00001001)

const int digits[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

void shiftNumber(byte num) {
  // Shift a byte to the shift register
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, num);
  digitalWrite(LATCH, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LATCH, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(TR1, OUTPUT);
  pinMode(TR2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

unsigned long t;
void loop() {
  // put your main code here, to run repeatedly:
  for (int d1 = 0; d1 < 10; d1++) {
    for (int d2 = 0; d2 < 10; d2++) {
      t = millis();
      while (millis() < t + 200) {
        // Turn off TR2
        digitalWrite(TR2, HIGH);
        shiftNumber(digits[d1]);
        // Activate TR1
        digitalWrite(TR1, LOW);
        delay(3);

        digitalWrite(TR1, HIGH);
        shiftNumber(digits[d2]);
        // Activate TR2
        digitalWrite(TR2, LOW);
        delay(3);

      }
    }
  }
}
