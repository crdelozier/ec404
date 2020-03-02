#pragma once

#include <list>

class Process;

class Scheduler{
protected:
  Process *running;
  std::list<Process*> readyQueue;
  std::list<Process*> waitQueue;
public:
  Scheduler();
  virtual Process* chooseProcess(unsigned long time) = 0;
  void addToReady(Process *p);
  void addToWait(Process *p);
  void handleWaits(unsigned long time);
  void handleWaiting(Process *p);
};

class FCFS : public Scheduler{
public:
  virtual Process *chooseProcess(unsigned long time);
};
