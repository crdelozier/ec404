#include <list>

#include <stdlib.h>
#include <sys/mman.h>

using namespace std;

class TwoLevelTable{
   
public:
  TwoLevelTable(){
    // Constructor, initialize class members
  }

  ~TwoLevelTable(){
    // Destructor, perform any cleanup
  }
  
  void setSize(void*address, size_t size){
    // TODO: Store the size in the two level table
  }
  
  size_t getSize(void *address){
    // TODO: Retrieve the size of the allocation
    // from the two level table
    return 0;
  }
};

struct Block{
  size_t size;
  void *block;
};

list<Block> freeBlocks;

extern "C" void *mymalloc(size_t size){
  // TODO: Replace this with your implementation of malloc
  return malloc(size);
}

extern "C" void myfree(void *address){
  // TODO: Replace this with your implementation of free
  return free(address);
}
