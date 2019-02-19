#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>

void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

Uint32 setColor(bool state, SDL_Surface* dest);

void fillCell(int XCells, SDL_Surface* dest, int surface_x, int surface_y, Uint32 pixel );


class Grid{
protected:
  bool** buffer=NULL;
  bool** grid=NULL;
  int grid_w=0;
  int grid_h=0;
  int XCells=0;
  Uint32 red;
  Uint32 green;
  Uint32 blue;
public:
  Grid(int cellW,
    int surface_w,
    int surface_h,
    Uint32 r=255,
    Uint32 g=255,
    Uint32 b=255);
  bool** getGrid();
  bool getState(int x, int y);
  void setState(int x, int y, bool state);
  void transform(SDL_Surface* dest);
  void Update();

  void draw_rectangle(
  int x,
  int y,
  int rect_width,
  int rect_height );

  void draw_circle(  int x, int y, int r);

  int w();
  int h();
  int cellW();
  ~Grid();
private:
    bool decideState(int x, int y);
    int adjacent(int x, int y);
};


#endif
