#pragma once

enum BurstType{CPU,IO};

class Burst{
public:
  BurstType type;
  unsigned long length;

  Burst(BurstType _type, unsigned long _length);

  void step();
  bool isDone();
};
