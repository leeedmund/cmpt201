#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t resource_a;
pthread_mutex_t resource_b;

void *thread1(void *arg) {
  while (1) {
    pthread_mutex_lock(&resource_a);
    printf("Thread 1 acquired");
  }
}
