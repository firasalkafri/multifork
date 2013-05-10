/* Includes */
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <sys/wait.h>   /* Wait for Process Termination */
#include <stdlib.h>     /* General Utilities */

void myFork (int);

int main()
{
  myFork(10); //forking 10 children
}

void myFork (int nChildren) {
    int i;
    pid_t pid;
    for (i = 1; i <= nChildren; i++) {
        pid = fork();
        if (pid == -1) {
            printf("Can't fork child number %d\n",i); //some error handling
            return;
        }
        if (pid == 0) {
            printf("I am a child: %d PID: %d\n",i, getpid());  //here you can handle your newly forked child
            return;
        }
    }
}
