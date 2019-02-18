#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "grid.h"

void Grid::draw_rectangle(
        		         int x,
        		         int y,
        		         int rect_width,
        		         int rect_height )
{
  int px, py;

  if(rect_width > 0 && rect_height > 0)
  {
    for(px = x; px < x + rect_width; px++)
    {
      for(py = y; py < y + rect_height; py++)
      {
        if(px == x || py == y || px == (x + rect_width - 1) || py == (y + rect_height - 1))
          setState(px,py,true);
      }
    }
  }
  if(rect_width < 0 && rect_height > 0)
  {
    for(px = x; px != x + rect_width; px--)
    {
      for(py = y; py < y + rect_height; py++)
      {
        if(px == x || py == y || px == (x + rect_width + 1) || py == (y + rect_height - 1))
          setState(px,py,true);
      }
    }
  }
  if(rect_width > 0 && rect_height < 0)
  {
    for(px = x; px < x + rect_width; px++)
    {
      for(py = y; py != y + rect_height; py--)
      {
        if(px == x || py == y || px == (x + rect_width - 1) || py == (y + rect_height + 1))
          setState(px,py,true);
      }
    }
  }
  if(rect_width < 0 && rect_height < 0)
  {
    for(px = x; px != x  + rect_width; px--)
    {
      for(py = y; py != y + rect_height; py--)
      {
        if(px == x || py == y || px == (x + rect_width + 1) || py == (y + rect_height + 1))
          setState(px,py,true);
      }
    }
  }
}
