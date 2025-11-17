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

Simplemente cambia el modo de pin del LED a `OUTPUT`, esto para poder hacer escrituras digitales en él.



### `loop()`

Emite una señal de SOS en morse continuamente usando la función `writeSOS()`, con pausas entre cada iteración de 1 segundo.



### `writeSOS()`

Contiene 3 bucles for para cada parte de la señal SOS:
... \_ \_ \_ ...
con pausas intermedias entre cada parpadeo

