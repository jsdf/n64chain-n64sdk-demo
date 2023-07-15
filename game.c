
#include <nusys.h>

#include <malloc.h>

#include "game.h"

void breakInThisFunction() {
  // asm("break  0");
  int i;
  int data[10];
  data[0] = 0;
  data[1] = 1;
  for (i = 2; i < 10; ++i) {
    data[i] = data[i - 2] + data[i - 1];
  }
}

int Game_update() {
  int result;
  int * val = malloc(sizeof(int));
  *val = 16777215;
  result = *val + 1;
  free(val);


  breakInThisFunction();

  return result;
}

