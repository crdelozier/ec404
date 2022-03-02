#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

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

int main(int argc, char **argv){
  if(argc < 2){
    cout << "Usage: " << argv[0] << " file1 [file2] ...\n";
    return 1;
  }

  cout << "File - Average - Median\n";
  
  for(int c = 1; c < argc; c++){
    vector<int> values = readFile(argv[c]);

    long sum = 0;
    for(int i = 0; i < values.size(); i++){
      sum += values[i];
    }

    sort(values.begin(),values.end());

    cout << argv[c] << " - " << sum/values.size() << " - " << values[values.size()/2] << "\n";
  }
  
  return 0;
}
