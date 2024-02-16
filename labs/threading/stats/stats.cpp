#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

using namespace std;

/*
 * Reads a file that contains integers into a vector
 * of ints.
 */
vector<int> readFile(string fileName){
  vector<int> values;
  fstream input(fileName);
  int i;

  while(input >> i){
    values.push_back(i);
  }
  
  return values;
}

void doSum(vector<int> values, int size, int start, atomic<long> *sum){
  for(int i = start; i < size; i++){
    *sum += values[i];
  }  
}

void doStats(char *fileName){
  vector<int> values = readFile(fileName);
  
  atomic<long> sum(0);
  if(values.size() > 1000){
    thread t1(doSum,values,values.size()/2,0,&sum);
    thread t2(doSum,values,values.size(),values.size()/2,&sum);
    t1.join();
    t2.join();
  }else{
    doSum(values, values.size(), 0, &sum);
  }
  
  sort(values.begin(),values.end());
  
  cout << fileName << " - " << sum/values.size() << " - "
       << values[values.size()/2] << "\n";  
}

int main(int argc, char **argv){
  if(argc < 2){
    cout << "Usage: " << argv[0] << " file1 [file2] ...\n";
    return 1;
  }

  cout << "File - Average - Median\n";

  vector<thread*> threads;
  
  for(int c = 1; c < argc; c++){
    thread *t = new thread(doStats,argv[c]);
    //doStats(argv[c]);
    threads.push_back(t);
  }

  for(int c = 1; c < argc; c++){
    threads[c-1]->join();
  }
  
  return 0;
}
