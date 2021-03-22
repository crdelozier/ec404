#include <atomic>

class Mutex{
  std::atomic<bool> is_locked;
public:
  Mutex() : is_locked(false) {}
  
  void lock(){
    bool expected = false;
    while(!is_locked.compare_exchange_strong(expected,true)){
      expected = false;
    }
  }

  void unlock(){
    is_locked = false;
  }
};
