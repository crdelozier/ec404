/*
 * Compile this using the following command:
 * gcc -o openmp openmp.c -fopenmp
 * 
 * You will also need to run the command below to 
 * set the number of threads:
 * export OMP_NUM_THREADS=4
 */

#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

#define N 20000000

int main(){
  int *A;
  int *B;
  int *C;

  A = (int*)malloc(sizeof(int) * N);
  B = (int*)malloc(sizeof(int) * N);
  C = (int*)malloc(sizeof(int) * N);

  for(int c = 0; c < N; c++){
    A[c] = rand() % 1000;
    B[c] = rand() % 1000;
  }

  #pragma omp parallel for
  for(int c = 0; c < N; c++){
    C[c] = A[c] + B[c];
  }

  int sum = 0;
  for(int c = 0; c < N; c++){
    sum += C[c];
  }

  printf("%d\n",sum);
}
