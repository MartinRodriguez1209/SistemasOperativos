#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {

  for (size_t i = 1; i < argc; i++) {
  }

  char buffer[100];
  char c;
  int count;

  int fr = open("/home/mrodriguez/Documentos/Sistemas "
                "Operativos/git/SistemasOperativos/Practico2/textin",
                O_RDONLY);

  int fw = open("/home/mrodriguez/Documentos/Sistemas "
                "Operativos/git/SistemasOperativos/Practico2/textout",
                O_WRONLY);

  while ((count = read(fr, buffer, 100)) > 0) {
    write(fw, buffer, count);
  }

  close(fw);
  close(fr);
}
