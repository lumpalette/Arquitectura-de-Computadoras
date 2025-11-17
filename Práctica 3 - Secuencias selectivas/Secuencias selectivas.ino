#define PIN_BUTTON_SOS 6
#define PIN_BUTTON_BLINK 7
#define PIN_BUTTON_PULSE 8
#define PIN_LED 9
#define DELAY_SLOW 100
#define DELAY_FAST 200

void setup() {
  pinMode(PIN_BUTTON_SOS, INPUT_PULLUP);
  pinMode(PIN_BUTTON_BLINK, INPUT_PULLUP);
  pinMode(PIN_BUTTON_PULSE, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  if (digitalRead(PIN_BUTTON_SOS) == LOW) {
    writeSOS();
    return;
  }

  if (digitalRead(PIN_BUTTON_BLINK) == LOW) {
    writeBlink();
    return;
  }

  if (digitalRead(PIN_BUTTON_PULSE) == LOW) {
      writePulse();
      return;
  }
}

void writeSOS() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(PIN_LED, HIGH);
    delay(DELAY_SLOW);
    digitalWrite(PIN_LED, LOW);
    delay(DELAY_SLOW);
  }
  
  delay(DELAY_SLOW);

  for (int i = 0; i < 3; i++) {
    digitalWrite(PIN_LED, HIGH);
    delay(DELAY_FAST);
    digitalWrite(PIN_LED, LOW);
    delay(DELAY_FAST);
  }

  delay(DELAY_SLOW);

  for (int i = 0; i < 3; i++) {
    digitalWrite(PIN_LED, HIGH);
    delay(DELAY_SLOW);
    digitalWrite(PIN_LED, LOW);
    delay(DELAY_SLOW);
  }

  digitalWrite(PIN_LED, 0);
}

void writeBlink() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(PIN_LED, HIGH);
    delay(DELAY_FAST);
    digitalWrite(PIN_LED, LOW);
    delay(DELAY_FAST);
  }

  digitalWrite(PIN_LED, 0);
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