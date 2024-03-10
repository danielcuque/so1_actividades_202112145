## Universidad de San Carlos de Guatemala

## Sistemas Operativos 1

### Daniel Estuardo Cuque Ruíz

### 202112145

#### Actividad 5

1. ¿Cuántos procesos únicos son creados?

    El programa crea procesos usando la función fork(). Hay tres llamadas a fork() en el código. Cada una de estas llamadas crea un nuevo proceso hijo, por lo tanto, se crearán tres procesos hijos. Sin embargo, uno de los procesos hijos no crea un nuevo hilo, mientras que los otros dos lo hacen. Por lo tanto, hay un total de tres procesos únicos creados.

2. ¿Cuántos hilos únicos son creados?

    El programa crea hilos utilizando pthread_create() en dos de los procesos hijos. Por lo tanto, se crean dos hilos únicos en total.