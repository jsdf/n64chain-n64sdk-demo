
#include <nusys.h>

#include <malloc.h>

#include "game.h"

int Game_update() {
  int * val = malloc(sizeof(int));
  *val = 16777215;
  int result = *val + 1;
  free(val);

  return result;
}
