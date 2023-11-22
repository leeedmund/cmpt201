
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/*
Write a program that calls fork() and prints out "parent" and the child PID if it is the parent process. 
If it is the child, print out "child" as well as its PID and the parent's PID. 
Use man getpid and man getppid to find out how to get the necessary PIDs.
*/

int main() {
  int value = fork();

  if (value != 0) {
   printf("parent: %d\n", value);
  } else {
    printf("child: %d\n", getppid());
  }
}
