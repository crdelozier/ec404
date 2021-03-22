#include <iostream>
#include <thread>

#include "barrier.hpp"

void race(int tid, Barrier *barrier){
  std::cout << tid;
  barrier->wait();
  std::cout << tid;
}

int main(){
  std::cout << "Start";
  
  Barrier *barrier = new Barrier(4);

  std::thread t1(race,1,barrier);
  std::thread t2(race,2,barrier);
  std::thread t3(race,3,barrier);
  std::thread t4(race,4,barrier);

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  std::cout << "Done\n";
  
  return 0;
}
