#include <atomic>

class Barrier{
  std::atomic<int> count;
  int n_threads;
public:
  Barrier(int threads) : count(0), n_threads(threads) {
  }
  
  void wait(){
    count++;
    while(count != n_threads){}
  }
};
