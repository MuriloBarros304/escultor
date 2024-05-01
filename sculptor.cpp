#include "sculptor.h"
#include <iostream>
#include <fstream>

Sculptor::Sculptor(int _nx, int _ny, int _nz){ // Construtor com argumentos
  nx = _nx;
  ny = _ny;
  nz = _nz;
  int i, j;

  // alocação dinâmica de memória
  v = new Voxel**[nx];
  v[0] = new Voxel*[nx*ny];
  v[0][0] = new Voxel[nx*ny*nz];
  // fixação dos ponteiros
  for(i=0;i<nx;i++){
    v[i] = v[0] + i * ny; // fixar as linhas nos planos
      for(j=0;j<ny;j++){
        v[i][j] = v[0][0] + (i * ny + j) * nz; // fixar as colunas 
      }
  }
}

Sculptor::~Sculptor(){
  delete[] v[0][0];
  delete[] v[0];
  delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float a){
  this->r = r; // Red
  this->g = g; // Green
  this->b = b; // Blue
  this->a = a; // Alpha
}

void Sculptor::putVoxel(int x, int y, int z){
  v[x][y][z].show = true;
  v[x][y][z].r = r;
  v[x][y][z].g = g;
  v[x][y][z].b = b;
  v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
  v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
  int i, j, k;
  for(i=x0;i<=x1;i++){
    for(j=y0;j<=y1;j++){
      for(k=z0;k<=z1;k++){
        v[i][j][k].show = true;
        v[i][j][k].r = r;
        v[i][j][k].g = g;
        v[i][j][k].b = b;
        v[i][j][k].a = a;
      }
    }
  }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
  int i, j, k;
  for(i=x0;i<=x1;i++){
    for(j=y0;j<=y1;j++){
      for(k=z0;k<=z1;k++){
        v[i][j][k].show = false; 
      }
    }
  }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
  int i, j, k;
  // (x - a)² + (y - b)² + (z - c)² = r²
  for(i=(xcenter-radius);i<=(xcenter+radius);i++){ 
    for(j=(ycenter-radius);j<=(ycenter+radius);j++){
      for(k=(zcenter-radius);k<=(zcenter+radius);k++){ 
        if(radius*radius == (i*xcenter)*(i-xcenter) + (j*ycenter)*(j-ycenter) + (k*zcenter)*(k-zcenter)){
          v[i][j][k].show = true;
          v[i][j][k].r = r;
          v[i][j][k].g = g;
          v[i][j][k].b = b;
          v[i][j][k].a = a;
        }
      }
    }
  }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  int i, j, k;
  for(i=0;i<=nx;i++){ 
    for(j=0;j<=ny;j++){ 
      for(k=0;k<=nz;k++){ 
        if(radius*radius == (i*xcenter)*(i-xcenter) + (j*ycenter)*(j-ycenter) + (k*zcenter)*(k-zcenter)){
          v[i][j][k].show = false;
        }
      }
    }
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  int i, j, k;
  // (x - xc)² / rx + (y - yc)² / ry + (z - zc)² / rz = 1
  for(i=0;i<=nx;i++){ 
    for(j=0;j<=ny;j++){ 
      for(k=0;k<=nz;k++){ 
        if(1 == ((i*xcenter)*(i-xcenter))/rx + ((j*ycenter)*(j-ycenter))/ry + ((k*zcenter)*(k-zcenter)/rz)){
          v[i][j][k].show = true;
          v[i][j][k].r = r;
          v[i][j][k].g = g;
          v[i][j][k].b = b;
          v[i][j][k].a = a;
        }
      }
    }
  }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  int i, j, k;
  for(i=0;i<=nx;i++){ 
    for(j=0;j<=ny;j++){ 
      for(k=0;k<=nz;k++){ 
        if(1 == ((i*xcenter)*(i-xcenter))/rx + ((j*ycenter)*(j-ycenter))/ry + ((k*zcenter)*(k-zcenter)/rz)){
          v[i][j][k].show = false;
        }
      }
    }
  }
}
