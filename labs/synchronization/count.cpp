#include <iostream>
#include <thread>

#include "mutex.hpp"
#include "ticket.hpp"

#define ITERS 10000000

unsigned long count = 0;
Mutex lock;

void increment(){
  for(int c = 0; c < ITERS; c++){
    lock.lock();
    count++;
    lock.unlock();
  }
}

int main(){
  std::thread t1(increment);
  std::thread t2(increment);

  t1.join();
  t2.join();

  std::cout << "Count: " << count << "\n";
  
  return 0;
}
