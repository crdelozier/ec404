#include <atomic>
#include <iostream>
#include <thread>

int num_threads = 4;
std::atomic<int> count;

void barrier(){
  // TODO: Wait for all of the threads to execute
  // this function
}

void race(int tid){
  std::cout << tid;
  barrier();
  std::cout << tid;
}

int main(){
  std::cout << "Start";

  std::thread t1(race,1);
  std::thread t2(race,2);
  std::thread t3(race,3);
  std::thread t4(race,4);

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  std::cout << "Done\n";
  
  return 0;
}
