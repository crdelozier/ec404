#pragma once

#include <list>

class rcu_list{
public:
  std::list<int*> priority_list;
  int users;
};

rcu_list* copy_list(rcu_list* from){
  rcu_list *new_list = new rcu_list;

  for(int *p : from->priority_list){
    if(*p > 0){
      new_list->priority_list.push_back(p);
    }
  }
  
  return new_list;
}

void delete_list(rcu_list *to_delete){
  delete to_delete;
}
