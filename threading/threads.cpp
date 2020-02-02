#include <atomic>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

vector<int> values;
unsigned long sum = 0;

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

int main(int argc, char **argv){
  if(argc < 2){
    cout << "Usage: " << argv[0] << " file1 [file2] ...\n";
    return 1;
  }

  for(int c = 1; c < argc; c++){
    readFile(argv[c]);
  }

  for(int c = 0; c < values.size(); c++){
    sum += values[c];
  }

  cout << "Total: " << sum << "\n";
  
  return 0;
}
