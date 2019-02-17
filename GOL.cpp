#include <cmath>
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <vector>
#include "GOL.h"

const bool alive = true;
const bool dead = false;

int adjacent (bool** Grid,
              unsigned int cols,
              unsigned int rows,
              int i,
              int j)
{
  int count = 0;

  //check the neighbourhood for any live neighbours
  for (int  k = i - 1; k <= i + 1; k++ )
  {
    for (int l = j - 1; l <= j + 1; l++ )
    {
      if (k != i || l != j)
      {
        if(Grid[k][l] == alive){
          count++;
        }
      }
    }
  }
  return count;
}

void decideState(bool** Grid,
                 unsigned int cols,
                 unsigned int rows)
{
  for (int i = 0; i < cols; i++ )
  {
    for (int j = 0; j < rows; j++ )
    {
      //get live neighbours
      int adj = adjacent(Grid, cols, rows, i, j);

      if ( adj == 2 )
        Grid[i][j] = grid[i][j];
      else if ( adj == 3 )
        Grid[i][j] = alive;
      else if ( adj > 3 )
        Grid[i][j] = dead;
      else if ( adj < 2 )
        Grid[i][j] = dead;
    }
  }
}
