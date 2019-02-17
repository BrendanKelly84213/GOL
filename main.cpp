 #include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <vector>
#include <assert.h>
#include "window.h"
#include "grid.h"
#include "GOL.h"

const int WIDTH = 640;
const int HEIGHT = 480;
const int X_CELLS=120;
const int y_CELLS=96;
const unsigned int FPS = 60;


int main()
{
  //Initialize variables
  bool running = true;
  bool** Grid = NULL;
  SDL_Event event;
  SDL_Init(SDL_INIT_VIDEO);
  int frameTime = 1;
  Window window = Window("window");

  SDL_Surface* surface = window.get_surface();

  Uint32 pixel = setColor(true, surface);

  fillCell(7, surface, WIDTH/2, HEIGHT/2, pixel);

  initGrid(Grid, 7, WIDTH, HEIGHT);

  transform(7, surface, WIDTH, HEIGHT, Grid);


  window.Update();

  while(running)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT){
        running = false;
      }
    }
  }

  destroyGrid(Grid, WIDTH/7);
  SDL_Quit();

  return 0;
}
