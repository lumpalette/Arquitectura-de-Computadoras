# Práctica 3: Secuencias selectivas



## Fecha de entrega:

17 de noviembre del 2025



## Placa:

Arduino uno R3



## Materiales externos utilizados:

* Laptop con Arduino IDE 2.3.6
* LED externo
* 11 cables
* 3 push buttons


## Link del video demostrativo

https://www.youtube.com/shorts/RMKuNRp1jnI


## Descripción del código:

El código usa 6 macros:

* `PIN_BUTTON_SOS`: El número del pin dónde se encuentra el botón para la señal SOS.
* `PIN_BUTTON_BLINK`: El número del pin dónde se encuentra el botón para la señal BLINK.
* `PIN_BUTTON_PULSE`: El número del pin dónde se encuentra el botón para la señal PULSE.
* `PIN_LED`: El número del pin dónde se encuentra el LED.
* `DELAY_FAST_TIME`: El tiempo (en milisegundos) entre parpadeos del LED que deben de ir más rápido.
* `DELAY_SLOW_TIME`: El tiempo (en milisegundos) entre parpadeos del LED que deben de ir más lento.



### `setup()`:

Cambia el modo de los pines de botones (6, 7 y 8) a INPUT_PULLUP, para que sean capaces de recibir señales de entrada por botones. Además, cambia el modo de pin del LED a `OUTPUT`, esto para poder hacer escrituras digitales y análogas en él.



### `loop()`:

Contiene 3 condicionales, cada uno preguntando si un botón de señal se ha pulsado en esa iteración. Si es así, la respectiva señal se comienza a ejecutar. Al pulsar un botón, la entrada de los demás botones se ve ignorada.


### `writeSOS()`:

Contiene 3 bucles for para cada parte de la señal SOS:
... \_ \_ \_ ...
con pausas intermedias entre cada parpadeo


### `writeBlink()`:

Contiene 1 bucle for con 7 iteraciones, dónde en cada una se emite un parpadeo del LED rápido.


### `writePulse()`:

Contiene 2 bucles for, que van incrementando y decrementando el brillo del LED hasta alcanzar el brillo máximo y mínimo, con una duración de 1 segundo y medio respectivamente.
