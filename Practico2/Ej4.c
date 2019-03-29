#include <stdio.h>

int main(int argc, char **argv) {

  for (size_t i = 1; i < argc; i++) {
  }

  FILE *filein;
  FILE *fileout;
  char buffer[100];
  char c;

  filein = fopen("/home/mrodriguez/Documentos/Sistemas "
                 "Operativos/git/SistemasOperativos/Practico2/textin",
                 "r");
  fileout = fopen("/home/mrodriguez/Documentos/Sistemas "
                  "Operativos/git/SistemasOperativos/Practico2/textout",
                  "w");

  while ((c = fgetc(filein)) != EOF) {
    fputc(c, fileout);
  }
  fclose(filein);
  fclose(fileout);
  printf("\n");
}
