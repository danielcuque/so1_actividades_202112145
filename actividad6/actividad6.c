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
