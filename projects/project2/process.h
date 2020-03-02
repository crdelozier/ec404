#pragma once

#include <atomic>
#include <string>
#include <queue>

#include "burst.h"

#define MAX_BURSTS 15
#define MAX_BURST_LENGTH 100

class Process{
  // Instance variables, private to each Process
  std::queue<Burst> bursts;
  
  unsigned long arrivalTime;
  unsigned long finishedTime;
  unsigned long waitingTime;
public:
  void parseBursts(std::string burstString);
  void randomize();
  bool isDone();
  bool isWaiting();
  bool isArriving(unsigned long time);
  bool hasArrived(unsigned long time);
  void step(BurstType type, unsigned long time);

  // stats stuff
  unsigned long getTurnaroundTime();
  unsigned long getWaitingTime();
  void incWait();
};
