#include "burst.h"

Burst::Burst(BurstType _type, unsigned long _length) : type(_type), length(_length){}

void Burst::step(){
  if(length > 0){
    length--;
  }
}

bool Burst::isDone(){
  return length == 0;
}
