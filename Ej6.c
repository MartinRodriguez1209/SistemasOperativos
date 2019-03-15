#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) {
    printf("hijo  Pid:%d\n", getpid());
    while (1) {
      /* code */
    }
  } else {
    waitpid(-1, &status, 0);
    printf("kill al hijo\n");
    if (WIFEXITED(status)) {
      printf("Estado de salida del hijo=%d  \n", WEXITSTATUS(status));
    }
    if (WIFSIGNALED(status)) {
      printf("Hijo termino por una señal:%d\n", WTERMSIG(status));
    }
  }
  return 0;
}
