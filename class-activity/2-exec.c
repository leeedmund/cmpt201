// main .c
/*
Write a program that creates a child process. 
The parent should call any one of exec functions that executes ls -al. 
The child should execute exa -al.
  -al actually needs to be -a -l.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int value = fork();
  if (value != 0) {
   execl("/bin/ls", "ls", "-al", ".", NULL);
  } else {
    execl("/bin/exa", "exa", "-al", ".", NULL);
  }

  while (1 > 0) {
    sleep(1);
  }
}
