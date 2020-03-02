#include <atomic>
#include <iostream>
#include <thread>

using namespace std;
#define ITERS 1000000

class PLock{
  atomic<bool> turn;
public:
  PLock() : turn(true) {}
  
  void lock(int tid){
    bool expected = true;
    while(!turn.compare_exchange_strong(expected,false)){
      // turn = false, expected = false, returned false
      expected = true;
    }
    // Only one thread at a time should be here
  }

  void unlock(int tid){
    // Reset the lock
    turn = true;
  }
};

PLock p;
unsigned long g_counter = 0;

void updateCount(int tid, int N){
  for(int c = 0; c < N; c++){
    p.lock(tid);
    g_counter++;
    p.unlock(tid);
  }
}

int main(){
  thread t0(updateCount,0,ITERS);
  thread t1(updateCount,1,ITERS);
  thread t2(updateCount,2,ITERS);
  thread t3(updateCount,3,ITERS);

  t0.join();
  t1.join();
  t2.join();
  t3.join();
  
  cout << g_counter << "\n";
  
  return 0;
}
