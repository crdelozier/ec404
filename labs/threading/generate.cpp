#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv){
  if(argc < 3){
    cout << "Usage: " << argv[0] << " filename number\n";
  }

  string fileName = argv[1];
  int N = atoi(argv[2]);

  fstream output(fileName, fstream::out);

  for(int c = 0; c < N; c++){
    output << (rand() % 100) << "\n";
  }

  output.close();
  
  return 0;
}

