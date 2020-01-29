#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(){
  pid_t pid;
  
  pid = fork();

  if (pid < 0) { /* error occurred */
    fprintf(stderr, "Fork Failed");
    return 1;
  }else if (pid == 0) {
    printf("1\n");
  }else {
    printf("2\n");
  }
  
  return 0;
}
