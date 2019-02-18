 #include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <assert.h>

#include "window.h"
#include "grid.h"


const int WIDTH = 640;
const int HEIGHT = 480;
const unsigned int FPS = 60;


int main()
{
  //Initialize variables
  bool running = true;
  SDL_Event event;
  SDL_Init(SDL_INIT_VIDEO);
  Window window = Window("window");
  SDL_Surface* surface = window.get_surface();
  Grid grid = Grid(5, window.getW(), window.getH());
  
  int glider[][2] = { {2,1}, {3,2}, {1,3}, {2,3}, {3,3} };
  for(int i=0; i < 5; i++){
    grid.setState(glider[i][0], glider[i][1], true);
  }

  while(running)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT){
        running = false;
      }
      grid.Update();
      grid.transform(surface);
      window.Update();


    }
  }


  SDL_Quit();

  return 0;
}
