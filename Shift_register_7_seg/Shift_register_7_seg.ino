// Shift register pins
#define LATCH (6)
#define DATA  (4)
#define CLOCK (5)


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
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 256; i++) {
    shiftNumber(i);
    digitalWrite(LED_BUILTIN, i % 2 ? HIGH : LOW);
    delay(100);
  }
}
