#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

  int in;
  int i;
  ssize_t d;

  while(1) {

    d = read(0, &in, 1);

    if(d<=0) {
      break;
    }

    for(i=0; i<8; i++) {
      putchar((in >> (7-i)) & 1);
    }

  }
  return 0;
}

