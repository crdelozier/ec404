#include <atomic>

class TicketLock{
  std::atomic<int> next_ticket;
  std::atomic<int> current_ticket;
public:
  TicketLock() : next_ticket(0), current_ticket(0) {}
  
  void lock(){
    // TODO: Get this thread's ticket number (replace
    // 0 with the correct operation)
    int my_ticket = next_ticket++;
    // TODO: Replace true with the condition to check
    // to ensure that only 1 thread enters its critical
    // section at a time
    while(my_ticket != current_ticket){}
  }

  void unlock(){
    // TODO: Release the lock and allow the next thread in
    // line to make progress
    current_ticket++;
  }
};
