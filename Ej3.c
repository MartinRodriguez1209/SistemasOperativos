#include <stdio.h>

int  main() {
  int pid;

	pid = fork();
	if (pid == 0) {
		printf("hijo Pid:%d \n",getpid());
	} else {
	printf("padre Pid:%d \n" ,getpid());
	}
	return 0;
}
