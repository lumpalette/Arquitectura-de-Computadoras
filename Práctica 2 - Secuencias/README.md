# Práctica 1: SOS



## Fecha de entrega

17 de noviembre del 2025



## Placa

Arduino uno R3



## Materiales externos utilizados:

* Laptop con Arduino IDE 2.3.6
* LED externo



## Descripción del código:

El código usa 3 macros:

* `PIN`: El número del pin dónde se encuentra el LED.
* `DELAY_FAST_TIME`: El tiempo (en milisegundos) entre parpadeos del LED que deben de ir más rápido.
* `DELAY_SLOW_TIME`: El tiempo (en milisegundos) entre parpadeos del LED que deben de ir más lento.



### `setup()`

Simplemente cambia el modo de pin del LED a `OUTPUT`, esto para poder hacer escrituras digitales y análogas en él.



### `loop()`

Emite una señal de SOS con `writeSOS()`, espera 1 segundo, emite 7 parpadeos rápidos con `writeBlink()`, espera 1 segundo, emite 1 pulso con `writePulse()` y espera 1 segundo. Después de eso, comienza una nueva iteración.



### `writeSOS()`

Contiene 3 bucles for para cada parte de la señal SOS:
... \_ \_ \_ ...
con pausas intermedias entre cada parpadeo


### `writeBlink`

Contiene 1 bucle for con 7 iteraciones, dónde en cada una se emite un parpadeo del LED rápido.


### `writePulse`

Contiene 2 bucles for, que van incrementando y decrementando el brillo del LED hasta alcanzar el brillo máximo y mínimo, con una duración de 1 segundo y medio respectivamente.
