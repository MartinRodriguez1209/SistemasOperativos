#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigmanager(int sig_num) {
	/* Reasignar la señal */
	signal(sig_num, sigmanager);


  if(sig_num ==SIGTSTP){
    exit(sig_num);
    }
    else{
      printf("Señal recibida\n");
    }
    fflush(stdout);
  }



  int main() {

    signal(SIGINT, sigmanager);//ctrl+c signal from keyboard
    signal(SIGTSTP, sigmanager);//ctrl+z signal stop type terminal
    while(1){
      printf("Programa esperando señal\n" );
      sleep(4);
    }

    return 0;
  }
