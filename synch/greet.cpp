#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

string name;

mutex cond_lock;
condition_variable cond;

void sayHello(){
  cout << "Hello!  What's your name?\n";

  // TODO: Wait for the other thread to provide a name

  cout << "Hi " << name << "!\n";
}

void sayHelloBack(){
  // TODO: Acquire the lock using a unique_lock
  cin >> name;
  cout << "Hi!  My name is " << name << "\n";
  // TODO: Notify the other thread that it can wake up
}

int main(){
  thread t1(sayHello);
  thread t2(sayHelloBack);

  t1.join();
  t2.join();
  
  return 0;
}
