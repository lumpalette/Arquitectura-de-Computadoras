#define PIN 9
#define DELAY_FAST_TIME 250   
#define DELAY_SLOW_TIME 750   

void setup() {
  pinMode(PIN, OUTPUT);
}

void loop() {
  writeSOS();
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