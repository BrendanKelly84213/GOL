 #include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <assert.h>

#include "Timer.h"
#include "window.h"
#include "grid.h"
#include "DrawRect.h"


const int WIDTH = 640;
const int HEIGHT = 480;
const unsigned int FPS = 10;


int main()
{
  //Initialize variables
  SDL_Init(SDL_INIT_VIDEO);
  Window window= Window("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOW_FULLSCREEN_DESKTOP);
  SDL_Surface* surface= window.get_surface();
  Grid grid= Grid(2, window.getW(), window.getH(), 255, 0, 0);
  Timer* mTimer;
  SDL_Event event;
  bool running = true;
  mTimer = Timer::Instance();


  int glider[][2] = { {2,1}, {3,2}, {1,3}, {2,3}, {3,3} };
  for(int i=0; i < 5; i++){
    grid.setState(glider[i][0], glider[i][1], true);
  }


  grid.draw_rectangle(grid.w()/4, grid.h()/4, grid.w()/2, grid.h()/4);
  grid.draw_rectangle(grid.w()/2, grid.h()/2, grid.w()/4, grid.h()/2);
  grid.draw_rectangle(grid.w()/1.5, grid.h()/1.5, grid.w()/4, grid.h()/4);
  grid.draw_rectangle(0, 0, grid.w()/4, grid.h()/4 );


  while(running)
  {
    mTimer->Update();

    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT || event.type == SDL_KEYDOWN){
        running = false;
      }
    }
    if(mTimer->deltaTime() >= 1.0f / FPS){
      grid.Update();
      grid.transform(surface);
      window.Update();
    }
  }


  SDL_Quit();

  return 0;
}
