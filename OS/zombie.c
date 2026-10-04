#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
 pid_t pid;
 pid = fork();
 if (pid < 0)
 {
 printf("Fork failed\n");
 return 1;
 }
 else if (pid == 0)
 {
 printf("Child process\n");
 printf("Child PID = %d\n", getpid());
 exit(0);
 }
 else
 {
 printf("Parent process\n");
 printf("Parent PID = %d\n", getpid());
 printf("Child PID = %d\n", pid);
 sleep(30);
 }
 return 0;
}
