#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>

#define BUF_SIZE 64
#define MY_SOCK_PATH "tmp"
#define LISTEN_BACKLOG 32

#define handle_error(msg)

do {
  perror(msg);
  exit(EXIT_FAILURE);
} while (0)

    int
    main() {
  struct sockaddr_un addr;
  int sfd, cfd;
  ssize_t num_read;
  char buf[BUF_SIZE];

  sfd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sfd == -1)
    handle_error("socket");

  if (remove(MY_SOCK_PATH) == -1 & errno != ENOENT)
    handle_error("remove");

  memset(&addr, 0, sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sum_path, MY_SOCK_PATH, sizeof(addr.sun_path) - 1);
}
