#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/*
Activity: write a program that writes X bytes to a file, move the file offset backward by X/2 bytes, 
and read and print out from the offset to EOF.

*/

int main() {
  char *str = "hello world";
  char buf[12];
  // open file for reading and writing with read and write
  // permission for user; create if it doesn't exist.
  int fd = open("tmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  write(fd, str, strlen(str));
  lseek(fd, -6, SEEK_CUR);
  read(fd, buf, 6);
  write(STDOUT_FILENO, buf, 6);
  // zsh shows % to indicate that there's no terminating new line.
  close(fd);
}