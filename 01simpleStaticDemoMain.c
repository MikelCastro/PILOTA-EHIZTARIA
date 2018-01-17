#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include "Sarrera.h"

int main(int argc, char * str[]) 
{
  if (sgHasieratu() == -1)
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    return 0;
  }
  sarrera();
  sgItxi();
  return 0;
}

