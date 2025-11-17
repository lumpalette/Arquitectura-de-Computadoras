#define PIN_BUTTON_INTERRUPT 2   
#define PIN_BUTTON_SOS 6 
#define PIN_BUTTON_BLINK 7
#define PIN_BUTTON_PULSE 8
#define PIN_LED 9
#define DELAY_SLOW 300
#define DELAY_FAST 100

typedef enum {
    SEQUENCE_NONE,
    SEQUENCE_SOS,
    SEQUENCE_BLINK,
    SEQUENCE_PULSE
} Sequence;

typedef enum {
    PROGRAM_RUNNING,
    PROGRAM_PAUSED,
    PROGRAM_RESUMING
} ProgramState;

volatile Sequence currentSequence = SEQUENCE_NONE;
volatile ProgramState programState = PROGRAM_RUNNING;

void setup() {
    pinMode(PIN_BUTTON_INTERRUPT, INPUT_PULLUP);
    pinMode(PIN_BUTTON_SOS, INPUT_PULLUP);
    pinMode(PIN_BUTTON_BLINK, INPUT_PULLUP);
    pinMode(PIN_BUTTON_PULSE, INPUT_PULLUP);
    
    pinMode(PIN_LED, OUTPUT);
    
    attachInterrupt(digitalPinToInterrupt(PIN_BUTTON_INTERRUPT), interruptHandler, FALLING);
}

void loop() {
    switch (programState) {
        case PROGRAM_PAUSED:
            break;
        case PROGRAM_RESUMING:
            programState = PROGRAM_RUNNING;
            //executeCurrentSequence();
            break;
        case PROGRAM_RUNNING:
            if (digitalRead(PIN_BUTTON_SOS) == LOW) {
                currentSequence = SEQUENCE_SOS;
                executeCurrentSequence();
            }
            if (digitalRead(PIN_BUTTON_BLINK) == LOW) {
                currentSequence = SEQUENCE_BLINK;
                executeCurrentSequence();
            }
            if (digitalRead(PIN_BUTTON_PULSE) == LOW) {
                currentSequence = SEQUENCE_PULSE;
                executeCurrentSequence();
            }
            break;
    }
}

void delayWithStop(unsigned long ms) {
    unsigned long start = millis();
    while ((millis() - start < ms) && (programState == PROGRAM_RUNNING)) {
        delay(1);
    }
}

void writeSOS() {
    static int counter = 0;
    static int section = 0;
    
    if (section == 0) {
        for (; (counter < 3) && (programState == PROGRAM_RUNNING); counter++) {
            digitalWrite(PIN_LED, HIGH);
            delayWithStop(DELAY_FAST);
            digitalWrite(PIN_LED, LOW);
            delayWithStop(DELAY_FAST);
        }
        if (programState != PROGRAM_RUNNING) {
            return;
        }
        section = 1;
        counter = 0;
    }
    
    delayWithStop(DELAY_SLOW);
    if (programState != PROGRAM_RUNNING) {
        return;
    }
    
    if (section == 1) {
        for (; (counter < 3) && (programState == PROGRAM_RUNNING); counter++) {
            digitalWrite(PIN_LED, HIGH);
            delayWithStop(DELAY_SLOW);
            digitalWrite(PIN_LED, LOW);
            delayWithStop(DELAY_SLOW);
        }
        if (programState != PROGRAM_RUNNING) {
            return;
        }
        section = 2;
        counter = 0;
    }
    
    delayWithStop(DELAY_SLOW);
    if (programState != PROGRAM_RUNNING) {
        return;
    }
    
    if (section == 2) {
        for (; (counter < 3) && (programState == PROGRAM_RUNNING); counter++) {
            digitalWrite(PIN_LED, HIGH);
            delayWithStop(DELAY_FAST);
            digitalWrite(PIN_LED, LOW);
            delayWithStop(DELAY_FAST);
        }
        if (programState != PROGRAM_RUNNING) {
            return;
        }
        section = 0;
        counter = 0;
    }
}

void writeBlink() {
    static int counter = 0;
    
    for (; (counter < 7) && (programState == PROGRAM_RUNNING); counter++) {
        digitalWrite(PIN_LED, HIGH);
        delayWithStop(DELAY_FAST);
        digitalWrite(PIN_LED, LOW);
        delayWithStop(DELAY_FAST);
    }
    
    // Si no está pausado, quiere decir que la secuencia se termino completamente.
    // Por lo tanto, reinicia el estado del programa.
    if (programState == PROGRAM_RUNNING) {
        currentSequence = SEQUENCE_NONE;
        counter = 0;
    }
}

void writePulse() {
    static float value = 0.0;
    static int section = 0;
    
    float seconds = 1.5;
    float increment = 1.0 / seconds;
    
    if (section == 0) {
        for (; (value < 255.0) && (programState == PROGRAM_RUNNING); value += increment) {
            analogWrite(PIN_LED, (int)value);
            delayWithStop(1000 / 255);
        }
        if (programState != PROGRAM_RUNNING) {
            digitalWrite(PIN_LED, LOW);
            return;
        }
        section = 1;
    }
    
    if (section == 1) {
        for (; (value > 0.0) && (programState == PROGRAM_RUNNING); value -= increment) {
            analogWrite(PIN_LED, (int)value);
            delayWithStop(1000 / 255);
        }
        if (programState != PROGRAM_RUNNING) {
            digitalWrite(PIN_LED, LOW);
            return;
        }
        section = 0;
    }
}

void executeCurrentSequence() {
    switch (currentSequence) {
        case SEQUENCE_SOS:
            writeSOS();
            break;
        case SEQUENCE_BLINK:
            writeBlink();
            break;
        case SEQUENCE_PULSE:
            writePulse();
            break;
    }
}

void interruptHandler() {
    static unsigned long lastInterruptTime = 0;
    
    unsigned long interruptTime = millis();
    
    if (interruptTime - lastInterruptTime > 50) {
        // Race condition de mrd
        if (programState == PROGRAM_RUNNING) {
            programState = PROGRAM_PAUSED;
        }
        else if (programState == PROGRAM_PAUSED) {
            programState = PROGRAM_RESUMING;
        }
        
        lastInterruptTime = interruptTime;
    }
}