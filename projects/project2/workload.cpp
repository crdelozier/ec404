#include <cstdlib>
#include <iostream>
#include "process.h"
#include "scheduler.h"
#include "workload.h"

using namespace std;

void Workload::run(Scheduler *sched){
  bool allDone = false;
  while(!allDone){
    allDone = true;
    for(Process *p : processes){
      allDone &= p->isDone();
      if(p->isArriving(time)){
	sched->addToReady(p);
      }
    }
    Process *p = sched->chooseProcess(time);
    if(p){
      p->step(BurstType::CPU,time);
    }
    sched->handleWaiting(p);
    sched->handleWaits(time);
    time++;
  }
}

void Workload::printStats(){
  unsigned long s = time / 1000;
  cout << "Throughput: " << processes.size() / s << " procs / second\n\n";

  unsigned long turnaroundSum = 0;
  unsigned long waitingSum = 0;
  cout << "Turnaround Time | Waiting Time\n";
  for(Process *p : processes){
    turnaroundSum += p->getTurnaroundTime();
    waitingSum += p->getWaitingTime();

    cout << p->getTurnaroundTime() << " | " << p->getWaitingTime() << "\n";
  }

  cout << "\nAverage Turnaround Time: " << (turnaroundSum / processes.size()) << " ms\n";
  cout << "Average Waiting Time: " << (waitingSum / processes.size()) << " ms\n";
}

void RandomWorkload::init(){
  int procs = (rand() % 20) + 10;
  for(int c = 0; c < procs; c++){
    Process *proc = new Process();
    proc->randomize();
    processes.push_back(proc);
  }
}
