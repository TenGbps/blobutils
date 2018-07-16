#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

  int in;
  int res;
  int i;
  ssize_t d;

  while(1) {

    res = 0;

    for(i=0; i<8; i++) {
      d = fread(&in, 1, 1, stdin);

      if(d<=0) {
        break;
      }

      res |= in << (7-i);
    }

    if(i>0) {
      putchar(res);
    }

    if(d<=0) {
      break;
    }

  }
  return 0;
}

