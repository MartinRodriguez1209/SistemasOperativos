#include <stdio.h>
#include <sys/types.h>

int  main() {
  pid_t pid;
  int status;

	pid = fork();
	if (pid == 0) {
    printf("hijo Pid:%d\n",getpid() );
    while (1) {
      /* code */
    }
	} else {
    waitpid(-1,&status,0);
    printf("kill al hijo\n");
    printf("padre Pid:%d \n" ,getpid());
    printf("Estado de salida del hijo=%d\n",status );//15=proceso terminado.
	}
	return 0;
}
