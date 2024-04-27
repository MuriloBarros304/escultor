#include "sculptor.h"
#include <iostream>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
  nx = _nx;
  ny = _ny;
  nz = _nz;

  // alocação dinâmica de memória
  Voxel v = new Voxel***[nx];
  Voxel v[0] = new Voxel**[ny*nx];
  Voxel v[0][0] = new Voxel*[nz*ny*nz];
}

Sculptor::~Sculptor(){

}

void Sculptor::setColor(float r, float g, float b, float a){
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}


