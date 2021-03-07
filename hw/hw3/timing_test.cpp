#include <unistd.h>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

typedef time_point<high_resolution_clock, duration<long, std::ratio<1, 1000000000> > > nano_time;

void do_time(nano_time start){
}

int main(){
  nano_time start = high_resolution_clock::now();

  thread t(do_time,start);
  nano_time end = high_resolution_clock::now();
  cout << "Time: " << duration_cast<nanoseconds>(end-start).count() << "\n";
  t.join();
  
  return 0;
}
