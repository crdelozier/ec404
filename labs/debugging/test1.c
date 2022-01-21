#include <stdio.h>

int main(){
  int x = 404;
  int *p = NULL;
  
  if(x != 404){
    p = &x;
  }

  *p = 500;

  printf("%d\n",x);
  
  return 0;
}
