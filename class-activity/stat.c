// write a program that
//
// receives one command line aargument (file path)
// uses stat() to et the file type (either regular file or directory)
// print out the file type

// man inode
// man 2stat
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
/*  struct stat sb;
  if (argc != 2) {
    exit(EXIT_FAILURE);
  }

  if (lstat(argv[1], &sb) == -1) {
    exit(EXIT_FAILURE);
  }

  printf("File Type:\n");
  switch (sb.st_mode & S_IFMT) {
  case S_ISREG:
    printf("File\n");
    break;
  case S_ISDIR:
    printf("Directory\n");
    break;
  default:
    printf("Unknown\n");
    break;
  }
  */

  char *path = argv[1];
  struct stat st;

  stat(path, &st);
  if (S_ISREG(st.st_mode)) {
    printf("Regular file\n");
  } else if (S_ISDIR(st.st_mode)) {
    printf("Directory\n");
  }
}
