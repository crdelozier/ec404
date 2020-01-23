#include <stdio.h>
#include <string.h>

int main(){
  char buffer[100];
  char password[5] = "ANSU";
  char newpass[5];
  int c;

  printf("Please enter the password: \n");
  fgets(buffer,100,stdin);

  for(c = 0; c < 4; c++){
    newpass[c] = password[3-c];
  }
  
  if(strncmp(buffer,newpass,4) == 0){
    printf("Correct!\n");
  }else{
    printf("Try again! Maybe a system utility could help you here...\n");
  }
  
  return 0;
}
