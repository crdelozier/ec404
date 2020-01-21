#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
  int x = 1;
  unsigned long long seconds = 0;
  
  while(x){
    sleep(1);
    seconds++;
    printf("I have been running for %llu seconds.\n",seconds);
  }

  printf("Thank you for saving me!\n");
  
  return 0;
}
