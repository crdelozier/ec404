#include <stdlib.h>
#include <stdio.h>

extern "C" void* mymalloc(size_t size);
extern "C" void myfree(void *address);

int main(int argc, char **argv){
  if(argc < 2){
    printf("Usage: %s [iterations]\n",argv[0]);
    return 1;
  }

  int totalAlloc = 0;
  int iters = atoi(argv[1]);
  char *lastAlloc = 0;
  
  for(int c = 0; c < iters; c++){
    int allocSize = rand() % 16384;

    if(allocSize < 4 && lastAlloc != NULL){
      myfree(lastAlloc);
    }else{
      lastAlloc = (char*)mymalloc(allocSize);
      totalAlloc += allocSize;
      // Test the memory to ensure that it worked properly
      for(int i = 0; i < allocSize; i++){
	lastAlloc[i] = 'a';
      }
    }
  }

  printf("Successfully allocated %d bytes!\n",totalAlloc);
  
  return 0;
}
