#include <atomic>
#include <iostream>
#include <thread>

#define ITERS 10000000

unsigned long count = 0;
std::atomic<int> now_serving;
std::atomic<int> next_ticket;

void acquire_lock(){
  // TODO: Get a ticket (load/read from next_ticket
  // into a local variable) and update next_ticket
  // to the next value at the same time
  // (Hint: What operator gives you the old value and then
  // updates the value?)
  
  // TODO: Wait until it's your turn using a while loop
  // (Hint: The condition should use both the ticket value
  // that you got from next_ticket and now_serving.)
}

void release_lock(){
  // TODO: Update now_serving to let the next thread go
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
