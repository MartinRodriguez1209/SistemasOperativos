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

  void sigmanager2(int sig_num,pid_t pid) {
  	/* Reasignar la señal */
  	signal(sig_num, sigmanager);
    kill(pid, sig_num);
      fflush(stdout);
    }

int  main() {
  pid_t pid;

	pid = fork();
	if (pid == 0){
    signal(SIGINT, sigmanager);//ctrl+c signal from keyboard
    signal(SIGTSTP, sigmanager);//ctrl+z
    sleep(1);
  } else{
    signal(SIGINT, sigmanager2);//ctrl+c signal from keyboard
    signal(SIGTSTP, sigmanager2);//ctrl+z
    while (1) {
    };
  }
	return 0;
}
