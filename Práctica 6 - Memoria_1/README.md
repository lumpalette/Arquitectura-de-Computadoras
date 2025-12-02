# Practica 6: Memorias_1


## Fecha de entrega:

1 de diciembre del 2025

## Placa:

Arduino Uno R3


## Materiales externos utilizados:

* Laptop con Arduino IDE 2.3.6
* 6 LEDs externos
* 7 botones 
* Cables y resistencias necesarias


##Link de video demostrativo:

https://www.youtube.com/shorts/keA6iIKrz90



## Descripción del código

El programa implementa un pequeño juego donde el sistema selecciona aleatoriamente la posición de una “mina” entre 6 posibilidades. El usuario debe adivinar presionando uno de los seis botones. Cada acierto o fallo se refleja a través de los LEDs.

El código utiliza las siguientes variables principales:

* `mineLocation[]`: Arreglo de 6 posiciones donde solo una contiene el valor *1* (la mina).
* `attempts`: Cantidad de intentos disponibles antes de reiniciar automáticamente (3).
* `pressedButton`: Guarda el número del botón presionado.
* `resetFlag`: Bandera que se activa cuando se presiona el botón de interrupción para reiniciar.



### `setup()`:

Configura lo siguiente:

* Inicializa comunicación Serial.
* Configura el botón de interrupción en el pin 2 usando `INPUT_PULLUP` y la interrupción `FALLING`.
* Configura los pines A0–A5 como entradas con `INPUT_PULLUP` para leer los 6 botones.
* Configura los pines 5–10 como salidas para los LEDs.
* Llama a la función `reset()` para iniciar el primer juego, generando una mina nueva y limpiando los LEDs.



### `loop()`:

Estructura principal del juego:

1. Revisa si el botón de interrupción fue presionado (resetFlag).
2. Si fue activado, ejecuta `reset()`.
3. Si quedan intentos (>0), llama a `checkAttempt()` para evaluar el botón presionado.
4. Si los intentos se agotan, imprime un mensaje por Serial y reinicia el juego automáticamente.



### `readButton()`:

Lee uno por uno los pines analógicos (A0–A5).
Si alguno está en estado `LOW`, significa que ese botón fue presionado.
Devuelve el número del botón correspondiente.

Incluye un pequeño `delay()` para evitar rebotes.



### `checkAttempt()`:

Evalúa el número del botón presionado:

* Si coincide con la posición de la mina (mineLocation[pos] == 1), ejecuta `successSecuence()` y luego reinicia el juego con `reset()`.
* Si es incorrecto:

  * Enciende el LED correspondiente.
  * Resta un intento.
  * Imprime el estado actual en el monitor serial.

Si el usuario falla los 3 intentos, se reinicia automáticamente.



### `reset()`:

* Limpia el arreglo `mineLocation[]`.
* Genera un número aleatorio entre 0 y 5 usando `randomSeed(micros())`.
* Coloca la mina en esa posición.
* Restablece el contador de intentos a 3.
* Imprime información de depuración (opcional).
* Ejecuta `resetSecuence()` para limpiar los LEDs.
* Apaga la bandera de interrupción.



### `resetSecuence()`:

Prende y apaga cada LED uno por uno rápidamente para indicar que el tablero fue reiniciado.


### `successSecuence()`:

Secuencia de celebración:
Apaga todos los LEDs y luego hace un patrón alternado entre LEDs impares y pares durante tres ciclos.


