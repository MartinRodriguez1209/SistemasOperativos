#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

pid_t pid;

void sigmanager(int sig_num) {
  /* Reasignar la señal */
  signal(sig_num, sigmanager);
  if (pid == 0) {
    printf("Hijo recibio señal\n");
    printf("id hijo:%d\n", getpid());
    exit(sig_num);
    printf("asdasd\n");
  } else {
    if (sig_num == SIGTERM) {
      printf("Enviando seña l al hijo\n");
      kill(pid, sig_num);
    }
  }
  fflush(stdout);
}

int main() {
  pid = fork();
  signal(SIGTERM, sigmanager); // ctrl+z
  if (pid == 0) {
    while (1) {
    }
  } else {
    printf("%d\n", getpid());
    waitpid(-1);
  }
  return 0;
}
