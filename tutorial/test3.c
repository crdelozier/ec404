#include <stdio.h>
#include <stdlib.h>

typedef struct point{
  int x;
  int y;
} point;

point *g;
point *h;

void foo(){
  point *p = (point*)malloc(sizeof(point));
  p->x = 1;
  p->y = 2;
  g = p;
  free(p);
}

void bar(){
  point *t = (point*)malloc(sizeof(point));
  t->x = 3;
  t->y = 4;
  h = t;
}

void baz(){
  g->x = 1;
  g->y = 2;
}

int main(){
  foo();
  bar();
  baz();

  printf("%d,%d\n",h->x, h->y);
  
  free(h);
  
  return 0;
}
