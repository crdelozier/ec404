#pragma once

#include <list>

class Process;

class Scheduler{
private:
  Process *running;
protected:
  std::list<Process*> readyQueue;
  std::list<Process*> waitQueue;
public:
  Scheduler();
  virtual void chooseProcess(unsigned long time) = 0;
  void addToReady(Process *p);
  void addToWait(Process *p);
  void handleWaits(unsigned long time);
  void handleWaiting(Process *p);
  void terminate(Process *p);
  void contextSwitch(Process *p);
  Process* getRunning();
  void checkRunningToWaiting();
  bool needToSchedule();
};

class FCFS : public Scheduler{
public:
  virtual void chooseProcess(unsigned long time) override;
};

class SJF : public Scheduler{
public:
  virtual void chooseProcess(unsigned long time) override;
};

class RR : public Scheduler{
public:
  virtual void chooseProcess(unsigned long time) override;
};

class STRF : public Scheduler{
public:
  virtual void chooseProcess(unsigned long time) override;
};

class Mine : public Scheduler{
public:
  virtual void chooseProcess(unsigned long time) override;
};
