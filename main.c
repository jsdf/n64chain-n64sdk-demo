
#include <nusys.h>
#include <malloc.h>

#include "stage00.h"


#define MEM_HEAP_SIZE 1024 * 512 * 1

char mem_heap[MEM_HEAP_SIZE];

NUContData  contdata[1]; // storage for controller 1 inputs

void mainproc(void)
{
  // reserve system heap memory
  InitHeap(mem_heap, MEM_HEAP_SIZE);

  // initialize the graphics system
  nuGfxInit();

  // initialize the controller manager
  nuContInit();

  // initialize the level
  initStage00();

  // set the update+draw callback to be called every frame
  nuGfxFuncSet((NUGfxFunc)stage00);

  // enable video output
  nuGfxDisplayOn();

  // send this thread into an infinite loop
  while(1)
    ;
}

