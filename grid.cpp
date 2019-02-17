#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "grid.h"

void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
      Uint8 *target_pixel = static_cast<Uint8 *>(surface->pixels)
                            + y * surface->pitch
                            + x * (sizeof *target_pixel)*(sizeof pixel);
      *(Uint32 *)target_pixel = pixel;
}

Uint32 setColor(bool state, SDL_Surface* dest)
{
  Uint32 pixel;
  Uint32 white = SDL_MapRGB(dest->format, 255, 255, 255);
  Uint32 black = SDL_MapRGB(dest->format, 0, 0, 0);
  if(state==true){
    pixel = white;
  }
  else{
    pixel = black;
  }
  return pixel;
}

void fillCell(int cellW, SDL_Surface* dest, int surface_x, int surface_y, Uint32 pixel )
{
  for(int i=0; i < cellW; i++){
    for(int j =0; j < cellW; j++){
      set_pixel(dest, i+surface_x, j+surface_y, pixel);
    }
  }
}

Grid::Grid(int cellW, int surface_w, int surface_h)
{
  grid_w = surface_w/cellW;
  grid_h = surface_h/cellW;

  grid = new bool*[grid_w];

  for(int i = 0; i < grid_w; i++){
    grid[i] = new bool[grid_h];
  }

  if(grid == 0x0){
    std::cerr << "Failed to initialize grid" << std::endl;
    exit( 1 );
  }

  for(int i=0; i < grid_w; i++){
    for(int j=0; j < grid_h; j++){
      grid[i][j] = false;
    }
  }
}

void Grid::transform(SDL_Surface* dest)
{
  bool state;
  Uint32 pixel;

  for(int i =0; i < grid_w; i++){
    for(int j= 0; j < grid_h; j++){
      state = grid[i][j];
      pixel = setColor(state, dest);
      fillCell(cellW, dest, i*cellW, j*cellW, pixel);
    }
  }
}


Grid::~Grid()
{
  for(int i =0; i < grid_w; i++){
    delete[] grid[i];
    grid[i] = NULL;
  }
  delete[] grid;
  grid = NULL;
}
