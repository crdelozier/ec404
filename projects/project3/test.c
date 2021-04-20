#include <stdlib.h>
#include <stdio.h>

extern "C" void* mymalloc(size_t size);
extern "C" void myfree(void *address);

int main(){
  int *x = (int*)mymalloc(sizeof(int));
  int *arr = (int*)mymalloc(100 * sizeof(int));

  free(x);
  free(arr);

  float *f1 = (float*)mymalloc(sizeof(float) * 100);
  float *f2 = (float*)mymalloc(sizeof(float) * 200);
  float *f3 = (float*)mymalloc(sizeof(float) * 300);
  float *f4 = (float*)mymalloc(sizeof(float) * 400);

  free(f1);
  free(f4);

  char *buf1 = (char*)mymalloc(8192);
  char *buf2 = (char*)mymalloc(16384);
  char *buf3 = (char*)mymalloc(4095);
  char *buf4 = (char*)mymalloc(400);

  free(f2);
  free(f3);

  free(buf1);
  free(buf2);
  free(buf3);
  free(buf4);

  printf("Passed all tests!\n");
  
  return 0;
}
