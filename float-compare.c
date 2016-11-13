#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include <unistd.h>

#include <stdarg.h>
#include <limits.h>

#include <fcntl.h>

#include <time.h>

#include <math.h>


int main(int argc, char **argv) {

  FILE * in1 = fopen(argv[1], "r");
  FILE * in2 = fopen(argv[2], "r");

  double delta = 0;

  int i = 0;

  while(!feof(in1)) {
    float x,y;
    fread(&x, sizeof(x), 1, in1);
    fread(&y, sizeof(x), 1, in2);
    if(fabs((double)x-(double)y) > delta) {
      delta = fabs((double)x-(double)y);
    }
    i++;
    if(i % 1000000 == 0) {
      printf("max delta %e\n", delta);
    }
  }
  printf("max delta %e\n", delta);
  if(delta > 0.0001) {
    exit(1);
  }
  exit(0);
}

