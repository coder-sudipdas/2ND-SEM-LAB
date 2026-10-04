#include<stdio.h>
#include<unistd.h>
int main()
{
fork();
printf("This is a process.\n");
printf("Process ID = %d\n",getpid());
return 0;
}
