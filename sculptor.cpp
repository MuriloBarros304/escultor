#include "sculptor.h"
#include <iostream>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
  nx = _nx;
  ny = _ny;
  nz = _nz;

  // alocação dinâmica de memória
  v = new Voxel**[nx];
  v[0] = new Voxel*[nx*ny];
  v[0][0] = new Voxel[nx*ny*nz];
  // fixação dos ponteiros
  for (i=0;i<nx;i++) {
    m[i] = m[0] + i * ny; // fixar as linhas nos planos
      for (j=0;j<ny;j++) {
        m[i][j] = m[0][0] + (i * ny + j) * nz; // fixar as colunas 
      }
  }
}

Sculptor::~Sculptor(){

}

void Sculptor::setColor(float r, float g, float b, float a){
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}


