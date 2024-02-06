#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <sys/mman.h>

using namespace std;

bool readBinaryFile(ifstream &file, vector<char>& binaryData){
  // Read the binary data from the file into the vector
  file.seekg(0, std::ios::end); // Move to the end of the file
  std::streampos fileSize = file.tellg(); // Get the file size
  file.seekg(0, std::ios::beg); // Move back to the beginning

  // Resize the vector to accommodate the file size
  binaryData.resize(static_cast<std::size_t>(fileSize));

  // Read the binary data into the vector
  file.read(binaryData.data(), fileSize);

  // Check if the reading was successful
  if (!file) {
    cerr << "Error reading file" << endl;
    return false;
  }

  // Close the file
  file.close();

  return true;
}

short readShort(char *start){
  short value;
  memcpy(&value,start,sizeof(short));
  return value;
}

int readInt(char *start){
  int value;
  memcpy(&value,start,sizeof(int));
  return value;
}

long readLong(char *start){
  long offset;
  memcpy(&offset,start,sizeof(long));
  return offset;
}

char* allocateMemory(size_t length){
  size_t pageSize = ((length / 4096) + 1) * 4096;
  return (char*)mmap(0,length,PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
}

// This creates a function pointer to the
// memory argument and runs the function
// The memory argument should point to the
// code loaded from the binary
void runAsProgram(char* memory){
  void (*fun)() = (void (*)())memory;
  fun();
}

class SectionHeader{
public:
  int nameOffset;
  int type;
  long flags;
  long addr;
  long offset;
  long size;
  int link;
  int info;
  long addralign;
  long entsize;
};

SectionHeader readSectionHeader(vector<char>& binaryData, long start){
  SectionHeader sh;

  // TODO: Read section header using format
  
  return sh;
}

int main(int argc, char **argv){
  if(argc < 2){
    cerr << "Usage: ./loader [file_to_load]" << endl;
    return 1;
  }
  
  ifstream fin(argv[1], std::ios::binary);
  vector<char> binaryData;

  if(!readBinaryFile(fin,binaryData)){
    return 1;
  }

  // TODO: Check ELF "magic" header
  

  // TODO: Initialize the ELF metadata
  // Note: You can skip fields that don't have a matching variable below
  // Always skip storing the version numbers (though you can verify that you're in the correct place
  // by checking them)
  char bitFormat;
  char endianFormat;
  char ABI;
  short objectFileType;
  short ISA;
  long sectionHeaderStart;
  short sectionHeaderSize;
  short sectionHeaderEntries = 0; // TODO: This should not be 0 once you've loaded the file, but it's set to 0 to not break the loop below
  short sectionHeaderNames;
  
  for(short c = 0; c < sectionHeaderEntries; c++){
    SectionHeader sh = readSectionHeader(binaryData,sectionHeaderStart + (c * sectionHeaderSize));
    // TODO: Load sections into memory
    // Note: Check the flags to determine if a section needs to occupy memory during the execution
  }

  // TODO: Relocate symbols that are used in the program (e.g. the msg in helloasm)

  // TODO: Use the runAsProgram function to execute the program that has been
  // loaded into memory by your previous code
  
  return 0;
}
