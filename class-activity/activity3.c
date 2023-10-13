
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void handle_sigint(int);
static char *buffer = "CTRL-C pressed.\n";

void handle_sigint(int signum) { write(STDOUT_FILENO, buffer, strlen(buffer)); }

int main() {
  struct sigaction handler;
  pid_t pid;

  handler.sa_handler = handle_sigint;
  handler.sa_flags = 0;
  sigemptyset(&handler.sa_mask);
  sigaction(SIGINT, &handler, NULL);

  pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid) {
    while (1) {
      sleep(5);
    }
  } else {
  }
}
