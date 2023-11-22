

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define _XOPEN_SOURCE >= 500

/*
Write a program that first creates a child process. The child process should run exa -al. The parent process should wait for the child process to terminate using waitpid(). If the child exited normally, print out "Child done." If not, print out the exit status.
*/


int main() {
  pid_t pid = fork();

  if (pid) {
    int wstatus = 0;
    if (waitpid(pid, &wstatus, 0) == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }

    if (WIFEXITED(wstatus)) {
      printf("Child done.\n");
    } else {
      printf("%d\n", WEXITSTATUS(wstatus));
    }
  } else {
    if (execl("/usr/bin/exa", "-a", "-l", NULL) == -1) {
      perror("execl");
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}
