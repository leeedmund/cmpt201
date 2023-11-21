
//write a program that takes a command line argument (file path) and create a 
//symbolic link and hard link 
// unlink hard link file

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  link(argv[1], "./threads.c");
  symlink(argv[1], "./threads.c");
  unlink("./bleh.c");
}
