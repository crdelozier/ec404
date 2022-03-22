#include <atomic>
#include <iostream>
#include <thread>

#define ITERS 10000000

unsigned long count = 0;
std::atomic<bool> is_locked;

void acquire_lock(){
  bool expected = false;
  while(!is_locked.compare_exchange_strong(expected,true)){
    expected = false;
  }
}

void release_lock(){
  is_locked = false;
}

void increment(){
  for(int c = 0; c < ITERS; c++){
    acquire_lock();
    count++;
    release_lock();
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
