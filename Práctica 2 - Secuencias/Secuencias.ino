#define PIN 9
#define DELAY_FAST_TIME 250
#define DELAY_SLOW_TIME 500

void setup() {
  pinMode(PIN, OUTPUT);
}

void loop() {
  writeSOS();
  delay(1000);

  writeBlink();
  delay(1000);

  writePulse();
  delay(1000);
}

void writeSOS() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(PIN, HIGH);
    delay(DELAY_FAST_TIME);
    digitalWrite(PIN, LOW);
    delay(DELAY_FAST_TIME);
  }

  delay(DELAY_FAST_TIME * 2); 

  for (int i = 0; i < 3; i++) {
    digitalWrite(PIN, HIGH);
    delay(DELAY_SLOW_TIME);
    digitalWrite(PIN, LOW);
    delay(DELAY_FAST_TIME);
  }

  delay(DELAY_FAST_TIME * 2);

  for (int i = 0; i < 3; i++) {
    digitalWrite(PIN, HIGH);
    delay(DELAY_FAST_TIME);
    digitalWrite(PIN, LOW);
    delay(DELAY_FAST_TIME);
  }
}

void writeBlink() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(PIN, HIGH);
    delay(DELAY_FAST_TIME);
    digitalWrite(PIN, LOW);
    delay(DELAY_FAST_TIME);
  }
}

void writePulse() {
  float seconds = 1.5;
  float increment = 1.0 / seconds;

  for (float value = 0.0; value < 255.0; value += increment) {
    analogWrite(PIN_LED, (int)value);
    delay(1000 / 255);
  }

  for (float value = 255.0; value > 0.0; value -= increment) {
    analogWrite(PIN_LED, (int)value);
    delay(1000 / 255);
  }

  analogWrite(PIN_LED, 0.0);
}