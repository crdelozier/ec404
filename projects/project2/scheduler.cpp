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

void Scheduler::terminate(Process *p){
  if(p == running){
    running = nullptr;
  }else{
    // Search the ready and waiting queues for p
    for(auto it = readyQueue.begin(); it != readyQueue.end(); it++){
      if(*it == p){
	readyQueue.erase(it);
	return;
      }
    }
    for(auto it = waitQueue.begin(); it != waitQueue.end(); it++){
      if(*it == p){
	waitQueue.erase(it);
	return;
      }
    }
  }
}

void Scheduler::contextSwitch(Process *p){
  if(running != nullptr){
    // Preempt the current process
    readyQueue.push_back(running);
  }
  running = p;
}

Process* Scheduler::getRunning(){
  return running;
}

void Scheduler::checkRunningToWaiting(){
  if(running != nullptr && running->isWaiting()){
    waitQueue.push_back(running);
    running = nullptr;
  }
}

bool Scheduler::needToSchedule(){
  return (running == nullptr || running->isDone());
}

void FCFS::chooseProcess(unsigned long time){
  // If we're not running a process, find a new one
  if(needToSchedule()){
    // Check to make sure we have things to schedule
    if(!readyQueue.empty()){
      // FCFS gets the first process from the readyQueue
      contextSwitch(readyQueue.front());
      readyQueue.pop_front();
    }
  }
}

void SJF::chooseProcess(unsigned long time){
  if(needToSchedule()){
    if(!readyQueue.empty()){
      Process *minProc = readyQueue.front();
      unsigned long min = minProc->getBurstLength();
      for(Process *p : readyQueue){
	if(min > p->getBurstLength()){
	  minProc = p;
	  min = p->getBurstLength();
	}
      }
      // Now I know the process with the shortest burst
      // So, remove it from the queue and schedule it
      contextSwitch(minProc);
      readyQueue.remove(minProc);
    }
  }
}

void RR::chooseProcess(unsigned long time){
  // TODO: Implement RR policy
  static int quantum = 5;
  quantum--;

  if(quantum == 0){
    // Schedule a new process
    
    quantum = 5;
  }
}

void STRF::chooseProcess(unsigned long time){
  // TODO: Implement STRF policy
}

void Mine::chooseProcess(unsigned long time){
  /*
   * TODO: This is your own scheduling algorithm.  Decide
   * on metrics to use to choose which process to run.
   */
  
}
