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
  virtual void addToReady(Process *p);
  virtual void addToWait(Process *p);
  virtual void handleWaits(unsigned long time);
  virtual void handleWaiting(Process *p);
};

class FCFS : public Scheduler{
public:
  virtual Process *chooseProcess(unsigned long time) override;
};

class SJF : public Scheduler{
public:
  virtual Process *chooseProcess(unsigned long time) override;
};

class RR : public Scheduler{
public:
  virtual Process *chooseProcess(unsigned long time) override;
};

class STRF : public Scheduler{
public:
  virtual Process *chooseProcess(unsigned long time) override;
};
