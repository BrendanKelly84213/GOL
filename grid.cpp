#include <iostream>
#include <cstdlib>
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
  Uint32 other = SDL_MapRGB(dest->format, 120,100,120);
  if(state==true){
    pixel = other;
  }
  else{
    pixel = black;
  }
  return pixel;
}

void fillCell(int XCells, SDL_Surface* dest, int surface_x, int surface_y, Uint32 pixel )
{
  for(int i=0; i < XCells; i++){
    for(int j =0; j < XCells; j++){
      set_pixel(dest, i+surface_x, j+surface_y, pixel);
    }
  }
}


Grid::Grid(int cellW, int surface_w, int surface_h)
{
  grid_w = surface_w/cellW;
  grid_h = surface_h/cellW;
  XCells = cellW;

  grid = new bool*[grid_w];
  buffer = new bool*[grid_w];

  for(int i = 0; i < grid_w; i++){
    grid[i] = new bool[grid_h];
    buffer[i] = new bool[grid_h];
  }

  if(grid == 0x0){
    std::cerr << "Failed to initialize grid" << std::endl;
    exit( 1 );
  }

  for(int i=0; i < grid_w; i++){
    for(int j=0; j < grid_h; j++){
      grid[i][j] = false;
      buffer[i][j] = false;
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
      fillCell(XCells, dest, i*XCells, j*XCells, pixel);
    }
  }
}

int Grid::adjacent (int x, int y)
{
  int count = 0;

  //check the neighbourhood for any live neighbours
  for (int  k = x - 1; k <= x + 1; k++ )
  {
    for (int l = y - 1; l <= y + 1; l++ )
    {
      if (k != x || l != y)
      {
        if(grid[(k + grid_w)%grid_w][(l + grid_h)%grid_h] == true){
          count++;
        }
      }
    }
  }
  return count;
}

bool Grid::decideState(int x, int y)
{
    //get live neighbours
    int adj = adjacent(x, y);
    bool P = grid[x][y];
    bool state;

    if ( adj == 2 )
      state = P;
    else if ( adj == 3 )
      state = true;
    else if ( adj > 3 )
      state = false;
    else if ( adj < 2 )
      state = false;

    return state;
}

void Grid::Update(){
  for(int i=0; i < grid_w; i++){
    for(int j=0; j < grid_h; j++){
      buffer[i][j] = decideState(i, j);
    }
  }
  for(int i=0; i < grid_w; i++){
    for(int j=0; j < grid_h; j++){
      bool P = buffer[i][j];
      setState(i, j, P);
    }
  }
}

bool** Grid::getGrid()
{
  return grid;
}

bool Grid::getState(int x, int y)
{
  return grid[x][y];
}

void Grid::setState(int x, int y, bool state){
  grid[x][y] = state;
}

int Grid::w(){
  return grid_w;
}

int Grid::h(){
  return grid_h;
}

int Grid::cellW(){
  return XCells;
}

Grid::~Grid()
{
  for(int i =0; i < grid_w; i++){
    delete[] grid[i];
    grid[i] = NULL;
    delete[] buffer[i];
    buffer[i] = NULL;
  }
  delete[] grid;
  grid = NULL;
  delete[] buffer;
  buffer = NULL;
}
