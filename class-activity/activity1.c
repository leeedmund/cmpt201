/////////////////////////////////////////////
// Error Handling
// Write a fork bomb
// Need to get the errno and print out corresponding definition ("EAGAIN"
// "ENOMEM", etc) Also use "perror()' to print out hte corresponding system
// error message.
// read: perror
/////////////////////////////////////////////

#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//#include <sys/wait.h>

int main() {
  int loop = 1;
  const char *s;
  while (loop) {
    //int value = fork();
  int value = fork();
  if ((value != -1)) {
   //   perror(s);
      //loop = 0;
   // } else {
      sleep(1);
  
  //perror();

    char *str = NULL;
    switch(errno) {
      case EAGAIN: 
        str = "EAGAIN";
        break;
      case ENOMEM:
        str = "ENOMEM";
        break;
      default:
        break;
    }
    perror("fork");
    printf("%s\n", str);
  }
  }
}
