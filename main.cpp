#include <iostream>
#include "sculptor.h"

int main(void){
  Sculptor teste(4, 3, 2);
  teste.setColor(0.5, 0.6, 0.0, 1);
  teste.putVoxel(1, 1, 1);
  teste.putEllipsoid(3, 3, 4, 2, 1, 5);
}