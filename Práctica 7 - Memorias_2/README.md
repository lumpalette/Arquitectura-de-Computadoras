# Práctica: Memorias_2


## Fecha de Entrega

9 de diciembre del 2025


## Placa:

Arduino Uno R3


## Materiales externos utilizados

* Laptop con Arduino IDE 2.3.6
* 1 x Placa Arduino Uno
* 1 x Cable USB
* 1 x Computadora con IDE de Arduino instalado
* 1 x Matriz de LEDs 8x8 (MAX7219 chip)
* 1 x Matriz de Teclado 4x4
* Cables de conexión (jumpers).
* Librerías de Arduino: Keypad.h y LedControl.h.


## Link del video demostrativo

https://www.youtube.com/shorts/Upm2IzEOxDM?feature=share


## Descripción del código

El código implementa el juego del gato (tic tac toe) entre un jugador humano y la computadora, utilizando una matriz LED para mostrar el tablero y un teclado matricial para la entrada del jugador.
Librerías utilizadas:

* Keypad.h: Para manejar la entrada del teclado matricial.
* LedControl.h: Para controlar la matriz LED.


### Configuración de pines:

Matriz LED:
* DIN: Pin 12
* CS: Pin 11
* CLK: Pin 10

Teclado matricial 4x4:
* Filas: A2, A3, A4, A5
* Columnas: 2, 3, 4, 5


### Variables globales importantes:

`game[3][3]`: Matriz que almacena el estado del juego ('X', 'O', '-').
`turn`: Contador de turnos (1-9).
`winner`: Almacena el ganador ('X', 'O', 'N' para ninguno).


### `setup()`:

*Inicia comunicación serial a 9600 baudios.
* Configura la matriz LED (intensidad, modo de funcionamiento).
* Dibuja el tablero de Tic Tac Toe en la matriz LED.


### `loop()`:

1. Verifica si hay un ganador usando checkWinner().
2. Si el jugador (X) gana, ejecuta xWins() y reinicia el juego.
3. Si la computadora (O) gana, ejecuta oWins() y reinicia el juego.
4. Si el tablero está lleno (turno > 9), declara empate y reinicia.
5. Alterna entre turnos: impares = jugador, pares = computadora.


### `readKeypad()`:

1. Lee la entrada del jugador a través del teclado matricial.
2. Los botones 1-9 corresponden a las posiciones del tablero.
3. El botón 'D' funciona como reset del juego.
4. Actualiza la matriz game y la visualización en la matriz LED.
5. Incrementa el contador de turnos después de un movimiento válido.


### `compTurn()`:

1.Genera un movimiento aleatorio para la computadora.
2. Verifica que la posición esté disponible.
3. Actualiza la matriz game y muestra una 'O' (2x2 LEDs encendidos) en la matriz LED.
4. Incrementa el contador de turnos.


### `checkWinner()`:

Verifica todas las posibles combinaciones ganadoras:
* 3 horizontales
* 3 verticales
* 2 diagonales

Retorna 'X', 'O' o 'N' (ninguno).


### `resetGame()`:

1. Reinicia todas las variables del juego.
2. Limpia la matriz LED.
3. Vuelve a dibujar el tablero.
4.Anuncia por serial el inicio de un nuevo juego.


### `xWins()` y `oWins()`:

Muestran animaciones en la matriz LED para indicar el ganador.
* 'X' se muestra como una X estilizada.
* 'O' se muestra como un círculo.
* Las animaciones parpadean dos veces antes de reiniciar el juego.


### `printGame()`:

* Imprime en el monitor serial el estado actual del juego.
* Muestra el número de turno y la disposición del tablero.
* Útil para depuración y seguimiento del juego.


## Características especiales:

* Sistema de turnos alternados entre jugador y computadora.
* Movimientos aleatorios para la computadora con randomSeed(micros()).
* Validación de movimientos (solo permite jugar en casillas vacías).
* Detección automática de fin de juego (ganador o empate).
* Reset manual con el botón 'D'.
* Interfaz visual completa en matriz LED.
* Log detallado en monitor serial.