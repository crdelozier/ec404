#include <cstdlib>
#include <iostream>
#include "process.h"

// The next two methods setup the CPU and I/O bursts for a fake process
void Process::parseBursts(std::string burstString){

}

void Process::randomize(){
  int num = (rand() % (MAX_BURSTS-1)) + 1;

  for(int c = 0; c < num; c++){
    bursts.push(Burst((c % 2 == 0) ? BurstType::CPU : BurstType::IO,
		      rand() % MAX_BURST_LENGTH));
  }

  arrivalTime = rand() % MAX_BURST_LENGTH;
}

bool Process::isArriving(unsigned long time){
  return arrivalTime == time;
}

bool Process::hasArrived(unsigned long time){
  return arrivalTime <= time;
}

bool Process::isDone(){
  return bursts.empty();
}

bool Process::isWaiting(){
  return !bursts.empty() && bursts.front().type == BurstType::IO;
}

void Process::step(BurstType type, unsigned long time){
  if(bursts.empty()){
    return;
  }
  
  Burst& burst = bursts.front();
  if(burst.type == type){
    burst.step();

    if(burst.isDone()){
      bursts.pop();
    }
  }

  if(bursts.empty()){
    finishedTime = time;
  }
}

unsigned long Process::getTurnaroundTime(){
  return finishedTime - arrivalTime;
}

unsigned long Process::getWaitingTime(){
  return waitingTime;
}

void Process::incWait(){
  waitingTime++;
}
