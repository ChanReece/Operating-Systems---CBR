#include  <stdio.h>
#include  <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
//Chandler Bursey-Reece

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     int i;
     pid_t  pid;
     for (i=0; i<2; i++){
     pid = fork();
     if (pid == 0) 
          ChildProcess(i);
     else if (pid < 0)
          printf("Issue in fork \n");
     }
          ParentProcess();
}


void  ChildProcess(int mypid)
{
     int randomnum;
     printf("Child Process PID: %d is going to sleep!", getpid());
     srand(getpid());
     randomnum = rand() % 10;
     sleep(randomnum + 1);
     printf("Child Pid: is awake!\nWhere is my Parent: %d?\n", getpid());
}

void  ParentProcess(void)
{
  unsigned int i; 
  signed int pid; 
  signed int status;
  
  for (i = 1; i<2; i++){
    pid = wait(&status);
    printf("Child PID: %d has completed\n", pid);
}