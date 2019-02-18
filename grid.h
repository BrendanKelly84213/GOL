#ifndef GRID_H
#define GRID_H

void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

Uint32 setColor(bool state, SDL_Surface* dest);

void fillCell(int XCells, SDL_Surface* dest, int surface_x, int surface_y, Uint32 pixel );


class Grid{
private:
  bool** grid=NULL;
  bool** buffer=NULL;
  int grid_w=0;
  int grid_h=0;
  int XCells=0;
public:
  Grid(int cellW, int surface_w, int surface_h);
  bool** getGrid();
  bool getState(int x, int y);
  void setState(int x, int y, bool state);
  void transform(SDL_Surface* dest);
  void Update();
  int w();
  int h();
  int cellW();
  ~Grid();
private:
    bool decideState(int x, int y);
    int adjacent(int x, int y);
};

#endif
