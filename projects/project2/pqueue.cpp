#include <atomic>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <unistd.h>

#include "list.h"

#define ITERS 20
#define HIGH 70

using namespace std;

rcu_list* high_priority;
rcu_list* low_priority;

bool keep_going = true;

// This thread creates new processes and adds
// them to the priority queues
void creator(){
  for(int c = 0; c < ITERS; c++){
    // Creates a new priority for the queue
    int *priority = new int;
    *priority = (rand() % 99) + 1;

    

    if(*priority >= HIGH){
      
    }else{
      
    }
      
    cout << "Adding new task with priority " << *priority << "\n";
    

    
    sleep(1);
  }

  exit(1);
}

// This thread schedules the highest priority process every second
void scheduler(){
  while(true){
    
    
    sleep((rand() % 3) + 1);
  }
}

int main(){
  high_priority = new rcu_list;
  low_priority = new rcu_list;
  
  thread creator_thread(creator);
  thread scheduler_thread(scheduler);

  creator_thread.join();
  scheduler_thread.join();
  
  return 0;
}
