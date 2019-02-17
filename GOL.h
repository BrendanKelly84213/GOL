#ifndef GOL_H
#define GOL_H

int adjacent (bool** Grid,
              unsigned int cols,
              unsigned int rows,
              int i,
              int j);

void decideState(bool** Grid,
                 unsigned int cols,
                 unsigned int rows);

#endif
