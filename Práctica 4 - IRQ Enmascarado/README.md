# Práctica 4: IRQ Enmascarado



## Fecha de Entrega:

17 de noviembre del 2025



## Placa:

Arduino Uno R3



## Materiales externos utilizados:

* Laptop con Arduino IDE 2.3.6
* 11 cables 
* Led Externo
* 4 push buttons


## Link del video demostrativo:

https://www.youtube.com/shorts/3A_zb33podU 


## Descripción del código

El código usa 5 macros:

* `PIN_BUTTON_SOS`: Pin del botón que activa la secuencia SOS.
* `PIN_BUTTON_BLINK`: Pin del botón que activa el parpadeo rápido.
* `PIN_BUTTON_PULSE`: Pin del botón que activa el pulso suave.
* `PIN_LED`: Pin donde está conectado el LED.
* `PIN_INTERRUPT`: Pin del botón que detiene cualquier secuencia mediante interrupción.

También usa dos macros de tiempo:

* `DELAY_SLOW`: Tiempo para los parpadeos lentos.
* `DELAY_FAST`: Tiempo para los parpadeos rápidos.



### `setup()`:

Configura todos los botones como INPUT_PULLUP (botón presionado = LOW).

Configura el LED como OUTPUT.

Configura el pin de interrupción para detectar una caída (FALLING) y llamar a stopAll() cuando se presiona el botón de paro.


### `loop()`:

Revisa continuamente qué botón está presionado:

*Si se presiona el botón SOS ejecuta writeSOS().
*Si se presiona el botón Blink ejecuta writeBlink().
*Si se presiona el botón Pulse ejecuta writePulse().

Cada vez que inicia una animación, reinicia stopFlag para permitir que se ejecute.


### `stopAll()`:

Función llamada por la interrupción.

Activa stopFlag para indicar que cualquier animación debe detenerse.

Apaga el LED inmediatamente.


### `writeSOS()`:

Emite la secuencia SOS en código Morse usando el LED

* Primero 3 parpadeos cortos (...)
* Luego 3 parpadeos largos (_ _ _)
* Luego otros 3 cortos (...)

Entre cada parte hay una pausa lenta (DELAY_SLOW).

Durante toda la secuencia, si stopFlag se activa, la animación se detiene.


### `writeBlink()`:

Hace parpadear el LED rápidamente 7 veces usando DELAY_FAST para encendidos y apagados.
También cancela si stopFlag se activa.


### `writePulse()`:

Genera un efecto de subir y bajar brillo, incrementa el brillo desde 0 hasta 255, luego baja de 255 hasta 0

Este proceso también se interrumpe si se activa `stopFlag`.


### `delayWithStop()`:

Pausa el programa sin bloquear completamente

Revisa constantemente si stopFlag se activó

Permite que la interrupción cancele el delay antes de que termine.