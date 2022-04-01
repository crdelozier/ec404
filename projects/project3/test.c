#include <stdlib.h>
#include <stdio.h>

extern char* mymalloc(size_t size, int policy);
extern void myfree(char *address);

int main(){
  char *x = mymalloc(4,1);
  char *arr = mymalloc(400,1);

  myfree(x);
  myfree(arr);

  char *buf1 = mymalloc(8192,1);
  char *buf2 = mymalloc(16384,1);
  char *buf3 = mymalloc(4095,1);
  myfree(buf3);
  char *buf4 = mymalloc(4097,1);

  myfree(buf1);
  myfree(buf4);
  myfree(buf2);

  printf("Passed all tests!\n");
}
