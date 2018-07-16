#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

  int in;
  int i;

  while(fread(&in, 1, 1, stdin) > 0) {

    for(i=0; i<8; i++) {
      putchar((in >> (7-i)) & 1);
    }

  }
  return 0;
}

