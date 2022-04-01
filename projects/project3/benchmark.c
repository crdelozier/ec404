#include <stdlib.h>
#include <stdio.h>

extern char* mymalloc(size_t size, int policy);
extern void myfree(char* address);

int main(int argc, char **argv){
  if(argc < 3){
    printf("Usage: %s [iterations] [policy (1=FIRST, 2=BEST, 3=WORST)]\n",argv[0]);
    return 1;
  }

  long totalAlloc = 0;
  int iters = atoi(argv[1]);
  int policy = atoi(argv[2]);

  char *lastAlloc = NULL;

  for(int c = 0; c < iters; c++){
    int allocSize = rand() % 16384;

    if(((rand() % 2) < 1) && lastAlloc != NULL){
      // Free ~half of the time
      myfree(lastAlloc);
      lastAlloc = NULL;
    }else{
      lastAlloc = mymalloc(allocSize,policy);
      totalAlloc += allocSize;
      
      // Test that the memory is usable
      for(int i = 0; i < allocSize; i++){
	lastAlloc[i] = 'a';
      }
    }
  }

  printf("Successfully allocated %ld bytes!\n",totalAlloc);
  
  return 0;
}
