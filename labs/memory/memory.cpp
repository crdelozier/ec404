#include <sys/mman.h>
#include <stdlib.h>
#include <iostream>
#include "MemoryAddressList.h"

using namespace std;

int main(int argc, char **argv){
  MemoryAddressList mal;
  
  void* ptr = (void*)argv[0];
  mal.addAddress(ptr,"Arguments");
  
  int *x = new int;
  mal.addAddress((void*)x,"Heap");

  mal.printAddresses();
  
  return 0;
}
