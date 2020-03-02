#pragma once

#include <vector>

class Process;
class Scheduler;

class Workload{
protected:
  std::vector<Process*> processes;
  unsigned long time;
public:
  virtual void init() = 0;
  void run(Scheduler *sched);
  void printStats();
};

class RandomWorkload : public Workload{
public:
  virtual void init();
};

/*
class FileWorkload : public Workload{
public:
  virtual void init();
};
*/
