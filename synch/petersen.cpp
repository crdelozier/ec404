#include <iostream>
#include <thread>

using namespace std;
#define ITERS 1000000

class PLock{
  int turn;
  bool flag[2];
public:
  void lock(int tid){
    flag[tid] = true;
    turn = 1 - tid;
    while(flag[1-tid] && turn == (1-tid)){}
  }

  void unlock(int tid){
    flag[tid] = false;
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

  t0.join();
  t1.join();
  
  cout << g_counter << "\n";
  
  return 0;
}
