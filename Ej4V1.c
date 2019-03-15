#include <stdio.h>
#include <sys/types.h>

int  main() {
  pid_t pid;
  int status;

	pid = fork();
	if (pid == 0) {
		printf("hijo Pid:%d \n",getpid());
	} else {
    waitpid(-1,&status,0);
    printf("padre Pid:%d \n" ,getpid());
    printf("Estado de salida del hijo=%d  \n",status );
	}
	return 0;
}
