#include <iostream>
#include <thread>

using namespace std;
#define ITERS 1000000

unsigned long g_counter = 0;

void updateCount(int N){
  for(int c = 0; c < N; c++){
    g_counter++;
  }
}

int main(){
  thread t1(updateCount,ITERS);
  thread t2(updateCount,ITERS);
  thread t3(updateCount,ITERS);
  thread t4(updateCount,ITERS);

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  cout << g_counter << "\n";
  
  return 0;
}
