#include <math.h>
#include "grid.h"

void Grid::draw_circle(  int x, int y, int r)
{
  for(int px=0; px<grid_w; px++)
  {
    for(int py=0; py<grid_h; py++)
    {
      double circle = sqrt((x-px)*(x-px)+(y-py)*(y-py));
      if(round(circle) < r)
      {
        setState(px, py, true);
      }
    }
  }
}
