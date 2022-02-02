#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
 
struct mesg_buffer{
  long mesg_type;
  char mesg_text[100];
} message;

int main(){
  pid_t pid;
  key_t key;
  int msgid;

  pid = fork();

  key = ftok("messagefile",65);
  msgid = msgget(key, 0666 | IPC_CREAT);

  if (pid < 0) { /* error occurred */
    fprintf(stderr, "Fork Failed");
    return 1;
  }else if (pid == 0) {
    printf("Child: %d\n",getpid());
    message.mesg_type = 1;
    strcpy(message.mesg_text,"Hello parental unit");
    msgsnd(msgid, &message, sizeof(message), 0);
  }else {
    int status;
    wait(&status);
    printf("Parent: %d, Child: %d\n",getpid(),pid);
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("%s\n",message.mesg_text);
    msgctl(msgid, IPC_RMID, NULL);
  }
  
  return 0;
}
