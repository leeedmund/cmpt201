
/*
Write a program that has two additional threads, - pthread_create twice
- define a bglobal variable called cnt. Two new threads should each run a while
loop (1000000 times) that keep incrementing cnt. The main thread should wait on
both threads, and when everything is done, main thread should print out the
value of cnt. Run it multiple times and see the output.
  - create a function and has a while loop inside it.
*/

//*
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;

static void *thread_func(void *arg) {
  for (int i = 0; i < 10000000; i++)
    cnt++;
  pthread_exit(0);
}

int main() {
  pthread_t t1;
  pthread_t t2;


  if (pthread_create(&t1, NULL, thread_func, NULL) != 0)
    perror("pthread_create");

  if (pthread_create(&t2, NULL, thread_func, NULL) != 0)
    perror("pthread_create");


  if (pthread_join(t1, NULL) != 0)
    perror("pthread_join");
  if (pthread_join(t2, NULL) != 0)
    perror("pthread_join");

  printf("%d\n", cnt);

  exit(EXIT_SUCCESS);
  
}
