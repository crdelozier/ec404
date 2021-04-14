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

  unique_lock<mutex> l(cond_lock); // cond_lock.lock();
  if(name.compare("") == 0){
    cond.wait(l); // Go to sleep until another thread wakes me up
  }

  cout << "Hi " << name << "!\n";
}

void sayHelloBack(){
  unique_lock<mutex> l(cond_lock);
  cin >> name;
  cout << "Hi!  My name is " << name << "\n";
  cond.notify_one(); // Wake up one other thread that is waiting on cond
}

int main(){
  thread t1(sayHello);
  thread t2(sayHelloBack);

  t1.join();
  t2.join();
  
  return 0;
}
