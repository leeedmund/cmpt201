// main .c
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // int true = 1;
  //  fork();
  int value = fork();
  // printf("%d", value);

  if (value != 0) {
   // printf("parent: %d\n", value);
   execl("/bin/ls", "ls", "-al", ".", NULL);
  } else {
    //printf("child: %d\n", getppid());
    execl("/bin/exa", "exa", "-al", ".", NULL);
  }

  while (1 > 0) {
    sleep(1);
  }

  // exec:
  // program that calls any one of exec functions that executes ls-:

  // }
  // getpid
  // getppid
  // parent process: print out parent and pid of the child
  // child process print out child and the pid of the parent
  //
  //
  // use:
  // return value from fork()
  // getpid()
  // getppid()
  //  printf("parent: %d\n", );
}
