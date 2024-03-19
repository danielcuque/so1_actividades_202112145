## Universidad de San Carlos de Guatemala

## Sistemas Operativos 1

### Daniel Estuardo Cuque Ruíz

### 202112145

#### Actividad 5


1. **Diferencia entre Scheduling Permisivo y No Permisivo:**
   - **Permisivo:** En este tipo de scheduling, un proceso que ha sido asignado al CPU puede ser expulsado si una tarea de mayor prioridad necesita ejecutarse. Es decir, el sistema permite que un proceso en ejecución sea interrumpido si es necesario para dar paso a otro proceso de mayor prioridad.
   - **No Permisivo:** Aquí, una vez que un proceso ha sido asignado al CPU, no se le permite ser interrumpido hasta que haya terminado su ejecución o haya liberado el CPU voluntariamente. No se permite que procesos de menor prioridad interrumpan el proceso en ejecución.

2. **Algoritmo de Scheduling que podría provocar un bloqueo indefinido:**
   - **d. Priority:** Si un proceso de baja prioridad se bloquea o queda en espera, y todos los procesos restantes en la cola tienen una prioridad más alta, este proceso de baja prioridad podría quedar excluido indefinidamente, lo que puede llevar a un bloqueo indefinido.

3. **Probabilidades de cambios de contexto voluntarios y no voluntarios:**
   - **I/O-bound:** Es más probable que los programas I/O-bound tengan cambios de contexto voluntarios, ya que pueden realizar operaciones de E/S y liberar el CPU voluntariamente mientras esperan la finalización de operaciones de entrada/salida.
   - **CPU-bound:** Por otro lado, los programas CPU-bound tienen más probabilidades de tener cambios de contexto no voluntarios, ya que requieren más tiempo de CPU y, por lo tanto, pueden ser expulsados del CPU cuando su tiempo de ejecución se agota para dar paso a otros procesos.

4. **Programa en C para crear un proceso hijo que se convierta en zombie:**

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error al crear el proceso hijo\n");
        return 1;
    } else if (pid == 0) {
        // Código del proceso hijo
        printf("Proceso hijo creado\n");
        exit(0); // El proceso hijo sale inmediatamente
    } else {
        // Código del proceso padre
        printf("Esperando 10 segundos para asegurar que el proceso hijo se convierta en zombie...\n");
        sleep(10); // Espera 10 segundos para asegurar que el proceso hijo se convierta en zombie
        printf("Proceso padre terminado\n");
    }

    return 0;
}
```
   