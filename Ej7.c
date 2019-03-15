#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void sigmanager(int sig_num) {
	/* Reasignar la señal */
	signal(sig_num, sigmanager);

  printf("Hijo recibio señal\n" );
  printf("id hijo:%d\n",getpid() );
  if(sig_num ==SIGTSTP){
    exit(sig_num);
    }
    else{
      printf("continua\n");
    }
    fflush(stdout);
  }



int  main() {
  pid_t pid;

	pid = fork();
	if (pid == 0){
    signal(SIGINT, sigmanager);//ctrl+c signal from keyboard
    signal(SIGTSTP, sigmanager);//ctrl+z
    
  } else{
    kill(pid,signal(SIGINT,sigmanager));
		kill(pid,signal(SIGTSTP,sigmanager));
    while (1) {
    };
  }
	return 0;
}
