/////////////////////////////////////////////
/* Error Handling
Write a fork bomb. 
It needs to get the errno and print out corresponding definition (EAGAIN, ENOMEM, etc.). 
Also use perror() to print out the corresponding system error message.
*/
/////////////////////////////////////////////

#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//#include <sys/wait.h>

int main() {
  while (1) {
    if (fork() == -1) {
      char *str = NULL;
      switch (errno) {
      case EAGAIN:
        str = "EAGAIN";
        break;
      case ENOMEM:
        str = "ENOMEM";
        break;
      case ENOSYS:
        str = "ENOSYS";
        break;
      default:
        break;
      }
      perror("fork");
      printf("%s\n", str);
    }
  }
}
