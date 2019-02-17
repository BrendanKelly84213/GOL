#ifndef GRID_H
#define GRID_H

void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

Uint32 setColor(bool state, SDL_Surface* dest);

void fillCell(int cellW, SDL_Surface* dest, int surface_x, int surface_y, Uint32 pixel );

void transform(int cellW, SDL_Surface* dest, int surface_w, int surface_h, bool** grid);

void initGrid(bool** &grid, int cellW, int surface_w, int surface_h);

void destroyGrid(bool** grid, int grid_w);

#endif
