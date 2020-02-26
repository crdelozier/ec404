#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
#define ITERS 1000000

mutex l;
int turn;
bool flag[2];
unsigned long g_counter = 0;

void updateCounti(int N){
  for(int c = 0; c < N; c++){
    flag[0] = true;
    turn = 1;
    while(flag[1] && turn == 1){}
    g_counter++;
    flag[0] = false;
  }
}

void updateCountj(int N){
  for(int c = 0; c < N; c++){
    flag[1] = true;
    turn = 0;
    while(flag[0] && turn == 0){}
    g_counter++;
    flag[1] = false;
  }
}

int main(){
  thread t0(updateCounti,ITERS);
  thread t1(updateCountj,ITERS);

  t0.join();
  t1.join();
  
  cout << g_counter << "\n";
  
  return 0;
}
