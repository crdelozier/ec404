#include <list>

using namespace std;

const int FIRST_FIT = 1;
const int BEST_FIT = 2;
const int WORST_FIT = 3;

typedef struct block_t{
  size_t size;
  char* memory;
} block;

list<block> free_blocks;

char* find_first_fit(size_t size){
  return NULL;
}

char* find_best_fit(size_t size){
  return NULL;
}

char* find_worst_fit(size_t size){
  return NULL;
}

extern "C" char* mymalloc(size_t size, int policy){
  char* memory = NULL;

  // First, search for existing blocks of memory
  if(policy == FIRST_FIT){
    memory = find_first_fit(size);
  }else if(policy == BEST_FIT){
    memory = find_best_fit(size);
  }else{
    memory = find_worst_fit(size);
  }

  // TODO: Allocate new memory if there are no free blocks
  
  return memory;
}

extern "C" void myfree(char* address){
  // TODO: Return the memory pointed to by address
  // to the list of free blocks
}
