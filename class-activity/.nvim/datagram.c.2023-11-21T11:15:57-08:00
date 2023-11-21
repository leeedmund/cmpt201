#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

int main() {
  struct sockaddr_un addr;
  int sfd, cfd;
  ssize_t num_read;
  char buf[BUF_SIZE];

  sfd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sfd == -1)
    handle_error("socket");

  memset(&addr, 0 sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  strcopy(addr.sum_path, MY_SOCK_PATH, sizeof(addr.sun_path) - 1);
}
