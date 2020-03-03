#include "process.h"
#include "scheduler.h"

Scheduler::Scheduler() : running(nullptr){};

void Scheduler::addToReady(Process *p){
  readyQueue.push_back(p);
}

void Scheduler::addToWait(Process *p){
  waitQueue.push_back(p);
}

void Scheduler::handleWaits(unsigned long time){
  if(!waitQueue.empty()){
    std::list<Process*> ready; // list to move to ready queue
    for(Process *p : waitQueue){
      p->step(BurstType::IO,time);
      if(!p->isWaiting()){
	// Done waiting, move to ready
	ready.push_back(p);
      }
    }

    for(Process *p : ready){
      waitQueue.remove(p);
      readyQueue.push_back(p);
    }
  }
}

void Scheduler::handleWaiting(Process *p){
  if(!readyQueue.empty()){
    for(Process *other : readyQueue){
      if(other != p){
	other->incWait();
      }
    }
  }
}

Process* FCFS::chooseProcess(unsigned long time){
  // FCFS ignores time because it's nonpreemptive
  // Return the process at the front of the ready queue
  if(running != nullptr && running->isWaiting()){
    waitQueue.push_back(running);
    running = nullptr;
  }
  
  if(running == nullptr || running->isDone()){
    if(!readyQueue.empty()){
      running = readyQueue.front();
      readyQueue.pop_front();
    }
  }
  return running;
}

Process* SJF::chooseProcess(unsigned long time){
  /*
   * TODO: This should choose a process based on the 
   * shortest available job in the ready queue.
   */
  
  return nullptr;
}

Process* RR::chooseProcess(unsigned long time){
  /*
   * TODO: This should choose the first process in the
   * ready queue and run it for a given quantum.
   * You should experiment to choose a reasonable quantum
   * for the workloads provided.
   */
  return nullptr;
}

Process* STRF::chooseProcess(unsigned long time){
  /*
   * TODO: This should choose a process based on 
   * the shortest time remaining.  This algorithm should
   * interrupt a running process if a shorter one
   * enters the ready queue.
   */
  
  return nullptr;
}
