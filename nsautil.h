#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include <unistd.h>

#include <stdarg.h>
#include <limits.h>

//#include <sys/types.h>
//#include <sys/ipc.h>
//#include <sys/shm.h>

#include <fcntl.h>

#include <time.h>

#include <math.h>
#include <err.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <assert.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;


typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#define mask32 0xFFFFFFFF
#define MEGA 1000000
#define GIGA 1000000000

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define CLAMP(x, lower, upper) (MIN(upper, MAX(x, lower)))

void readn(int fd, char * buf, int n) {
  int pos = 0;
  while(pos<n) {
    ssize_t j = read(fd, buf+pos, n-pos);
    if(j <= 0) {
      fprintf(stderr, "error at %i\n", pos);
      exit(1);
    }
    pos += j;
  }
}

void writen(int fd, char * buf, int n) {
  int pos = 0;
  while(pos<n) {
    ssize_t j = write(fd, buf+pos, n-pos);
    if(j <= 0) {
      fprintf(stderr, "error at %i\n", pos);
      exit(1);
    }
    pos += j;
  }
}


