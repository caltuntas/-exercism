#include "secret_handshake.h"
#include <stdlib.h>
#include <stdio.h>

static char *list[] ={
  "wink",
  "double blink",
  "close your eyes",
  "jump"
};

const char **commands(size_t number)
{
  size_t counter =0;
  size_t x = number;
  while (x) {
    counter += x & 1;
    x = x >> 1;
  }

  int start =0;
  int inc = 1;
  if (number & 1 << 4){
    start =3;
    inc = -1;
    counter--;
  }

  const char **cmds = calloc(counter+1, sizeof *cmds);

  size_t i=0;
  while (i<counter) {
    for (int k=0; k<4; k++) {
      if (number & 1 << start) {
        cmds[i++] = list[start];
      }
      start +=inc;
    }
  }
  cmds[i] = NULL;
  return cmds;
}
