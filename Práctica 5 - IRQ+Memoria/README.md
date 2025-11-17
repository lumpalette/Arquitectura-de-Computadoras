Práctica 3 - IRQ + Memoria
Arduino UNO R3
Fecha de entrega:

17 de noviembre del 2025

Placa utilizada:

Arduino Uno R3

Materiales externos utilizados:

Laptop con Arduino IDE 2.3.x

Arduino UNO R3

LED en pin 9

Botones conectados a los pines:

2 → Botón de interrupción

6 → Botón SOS

7 → Botón Blink

8 → Botón Pulse

Descripción general del programa

Este proyecto implementa un sistema que permite controlar diferentes secuencias de parpadeo en un LED mediante botones físicos, utilizando además una interrupción externa para pausar y reanudar la ejecución.
El programa mantiene un estado interno que permite recordar cuál secuencia estaba activa incluso después de una pausa.

Macros definidas

El programa utiliza varias macros para simplificar la configuración:

PIN_BUTTON_INTERRUPT: Pin donde se conecta el botón de interrupción (pin 2).

PIN_BUTTON_SOS: Botón que activa la secuencia SOS.

PIN_BUTTON_BLINK: Botón que activa la secuencia Blink.

PIN_BUTTON_PULSE: Botón que activa la secuencia Pulse.

PIN_LED: Pin donde está conectado el LED (pin 9).

DELAY_SLOW: Tiempo de retardo lento (300 ms).

DELAY_FAST: Tiempo de retardo rápido (100 ms).

Estructuras de control
Enumeración Sequence

Define los tipos de secuencias disponibles:

SEQUENCE_NONE

SEQUENCE_SOS

SEQUENCE_BLINK

SEQUENCE_PULSE

Estados del programa

(Identificados dentro del código como programState):

PROGRAM_IDLE

PROGRAM_RUNNING

PROGRAM_PAUSED

PROGRAM_RESUMING

Estos estados permiten controlar la ejecución y retomar actividades después de una pausa generada por interrupción.

Funcionamiento del programa
setup()

Configura los pines de los botones como entradas con resistencia interna INPUT_PULLUP.

Configura el pin del LED como salida.

Activa la interrupción externa con attachInterrupt(), asociada al botón en el pin 2.

Inicializa el estado del programa en PROGRAM_IDLE.

loop()

El flujo principal:

Detecta si se presionó algún botón para seleccionar una secuencia (SOS, BLINK, PULSE).

Actualiza la variable global currentSequence.

Ejecuta la secuencia correspondiente si el programa está en modo RUNNING.

Si se genera una interrupción, el programa cambia su estado a PAUSED o RESUMING según corresponda.

En modo RESUMING, regresa a la secuencia anterior recordada.

Secuencias implementadas
1. Secuencia SOS (SEQUENCE_SOS)

Parpadeo en patrón Morse: