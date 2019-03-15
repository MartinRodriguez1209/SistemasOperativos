#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigmanager(int sig_num) {
  /* Reasignar la señal */
  signal(sig_num, sigmanager);
  kill (pid, sig_num);
  fflush(stdout);
}

int  main() {
  int pid;

	pid = fork();
	if (pid == 0) {
    printf("hijo\n" );
	} else {
    signal(SIGINT, sigmanager);//ctrl+c signal from keyboard
    signal(SIGTSTP, sigmanager);//ctrl+z
  }
	return 0;
}
