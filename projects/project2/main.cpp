#include <cstdlib>
#include <iostream>
#include <sstream>

#include "process.h"
#include "scheduler.h"
#include "workload.h"

using namespace std;

int main(int argc, char **argv){
  if(argc < 3){
    cout << "Usage: " << argv[0] << " [scheduler] [workload#]\n";
    cout << "Scheduler Options: FCFS, SJF, RR, Mine\n";
    return 1;
  }

  int workload = atoi(argv[2]);
  string scheduler = argv[1];

  Scheduler *sched = nullptr;
  
  if(scheduler.compare("FCFS") == 0){
    sched = new FCFS();
  }else if(scheduler.compare("SJF") == 0){
    sched = new SJF();
  }else if(scheduler.compare("RR") == 0){
    sched = new RR();
  }else{
    cerr << "ERROR: Did not recognize scheduler option, exiting\n";
    return 2;
  }

  Workload *work = nullptr;
  if(workload == 0){
    // Random workload
    work = new RandomWorkload();
  }else{
    // Load workload from file
    stringstream ss;
    ss << "workload" << workload << ".txt";
    work = new FileWorkload(ss.str());
  }

  work->init();
  work->run(sched);
  work->printStats();

  return 0;
}
