#include <atomic>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

vector<int> values;
unsigned long total = 0;

/*
 * Reads a file that contains integers into the 
 * values vector.
 */
void readFile(string fileName){
  fstream input(fileName);
  int i;

  while(input >> i){
    values.push_back(i);
  }
}

void sum(unsigned long *result, int start, int end){
  unsigned long s = 0;
  for(int c = start; c < end; c++){
    s += values[c];
  }
  *result = s;
}

int main(int argc, char **argv){
  if(argc < 2){
    cout << "Usage: " << argv[0] << " file1 [file2] ...\n";
    return 1;
  }
  
  // If more than one file, read files on 1 thread, and sum them
  // on another thread (concurrency)

  // Read a file on each thread
  for(int c = 1; c < argc; c++){
    readFile(argv[c]);
  }

  // Split the values and sum half (or some small portion) of values
  // on each thread
  //for(int c = 0; c < values.size(); c++){
  //  sum += values[c];
  //}
  unsigned long r1 = 0;
  unsigned long r2 = 0;
  thread t1(sum,&r1,0,values.size()/2);
  thread t2(sum,&r2,(values.size()/2)+1,values.size());

  total = r1+r2;
  
  cout << "Total: " << total << "\n";
  
  return 0;
}
