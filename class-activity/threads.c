
/*

Write a program that:
  - main thread creates another therad. - pthread_create
  - in the manin thread, it should print out ht e new thread's id, wait until it
terminates and print out the return value - pthread, phtread_join
  - the other thread should get a string from the main thread as the argument,
print that out as well as its own ID, and reutrn the length of the received
string.
      - string as the main argument
      - via created thread; print out the string, id, and length

functions to use:

- pthread_create
- pthread_join

  */


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void *thread_func(void *arg) {
  char *s = arg;
  printf("received %s", s);
  pthread_t id = pthread_self();
  printf("New thread id: %ld\n", id);
  pthread_exit((void *)strlen(s));
}

int main() {
  pthread_t t1;
  void *res;
  int s;

  s = pthread_create(&t1, NULL, thread_func, "hello world\n");
  if (s != 0) {
    perror("pthread_create");
  }

  printf("New thread ID: %ld\n", t1);
  s = pthread_join(t1, &res);
  if (s != 0) {
    perror("pthread_join");
  }
  printf("Return %ld\n", (long)res);
  return 1;
}


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
  int i = 0;
  while (i < 10000000) {
    cnt++;
    i++;
  }
  pthread_exit(0);
  // char *s = arg;
  // printf("received %s", s);
  // pthread_t id = pthread_self();
  // printf("New thread id: %ld\n", id);
  // pthread_exit((void *)strlen(s));
}

// int cnt = 0;

int main() {
  pthread_t t1;
  pthread_t t2;
//  void *res;
  // int s;
  // int s2;
  pthread_create(&t1, NULL, thread_func, NULL);
  // s2 = pthread_create(&t2, NULL, thread_func, NULL);
  /*if (s != 0) {
    perror("pthread_create");
  }
*/
  // printf("New thread ID: %ld\n", t1);
  pthread_join(t1, NULL);
  pthread_create(&t2, NULL, thread_func, NULL);
  pthread_join(t2, NULL);
  /*if (s != 0) {
    perror("pthread_join");
  }*/
  printf("Return %d\n", cnt);
  return 1;
}
