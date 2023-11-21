#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main () {
  char *str = "hello world";
  char buf[6];
  int fd = open("tmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  write(fd, str, strlen(str));
  lseek(fd, -6, SEEK_CUR);
  read(fd, buf, 6);
  write(STDOUT_FILENO, buf, 6);
  close(fd);
}
