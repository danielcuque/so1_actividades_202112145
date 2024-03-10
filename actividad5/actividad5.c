#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread created\n");
    pthread_exit(NULL);
}

int main() {
    pid_t pid;
    pthread_t thread;
    int num_processes = 0;
    int num_threads = 0;

    pid = fork();
    if (pid == 0) { /* child process */
        pthread_create(&thread, NULL, thread_function, NULL);
        num_threads++;
    } else if (pid > 0) {
        num_processes++;
        pid = fork();
        if (pid == 0) { /* child process */
            pthread_create(&thread, NULL, thread_function, NULL);
            num_threads++;
        } else if (pid > 0) {
            num_processes++;
            fork();
            if (pid == 0) { /* child process */
                pthread_create(&thread, NULL, thread_function, NULL);
                num_threads++;
            } else if (pid > 0) {
                num_processes++;
            } else {
                perror("fork");
                exit(EXIT_FAILURE);
            }
        } else {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    printf("Number of unique processes created: %d\n", num_processes);
    printf("Number of unique threads created: %d\n", num_threads);

    return 0;
}
