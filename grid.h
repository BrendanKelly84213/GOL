#ifndef GRID_H
#define GRID_H

void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

Uint32 setColor(bool state, SDL_Surface* dest);

void fillCell(int cellW, SDL_Surface* dest, int surface_x, int surface_y, Uint32 pixel );

class Grid{
protected:
  bool** grid=NULL;
  int grid_w=0;
  int grid_h=0;
  int cellW=0;
public:
  Grid(int cellW, int surface_w, int surface_h);
  void transform(SDL_Surface* dest);
  ~Grid();
};


#endif
