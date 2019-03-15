#include <stdio.h>
#include <sys/types.h>

int  main() {
  pid_t pid;


	pid = fork();
	if (pid == 0) {
		printf("hijo Pid:%d \n",getpid());
	} else {
    while(wait(NULL)>0)
    printf("padre Pid:%d \n" ,getpid());
	}
	return 0;
}
