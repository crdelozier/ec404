#define _GNU_SOURCE 1
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <ucontext.h>

/*
 * This handler ignores a segmentation fault by catching 
 * it and skipping the instruction that caused it.
 * THIS IS ONLY AN EXAMPLE.  DO NOT USE THIS IN THE REAL WORLD.
 */
static void handler(int sig, siginfo_t *si, void *ptr){
    printf("Got SIGSEGV at address: 0x%lx\n",(long) si->si_addr);
    // Get the current instruction pointer (RIP) (e.g. PC)
    ucontext_t *uc = (ucontext_t *)ptr;
    unsigned long long rip = uc->uc_mcontext.gregs[REG_RIP];
    rip += 6; // Skip 6 bytes to move past the store instruction
    uc->uc_mcontext.gregs[REG_RIP] = rip; // Save PC in context
}

int main(){
  struct sigaction sa;
  
  sa.sa_flags = SA_SIGINFO;
  sigemptyset(&sa.sa_mask);
  sa.sa_sigaction = handler;
  if (sigaction(SIGSEGV, &sa, NULL) == -1){
    printf("Failed to install handler\n");
    return 1;
  }

  int *p = NULL;
  *p = 5;
  
  return 0;
}
