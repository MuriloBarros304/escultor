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

// utilizar herança a partir daqui
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
  int i, j, k;
  // (x - a)² + (y - b)² + (z - c)² = r²
  for(i=0;i<=nx;i++){ // (x - a)² = r² -> x² - 2xa + a² = r² -> x² = 2 * x * a - a * a
    for(j=0;j<=ny;j++){ // (y - b)² = r²
      for(k=0;k<=nz;k++){ // (z - c)² = r²
        if(i*i == (2*i*xcenter - xcenter*xcenter) and j*j == (2*j*ycenter - ycenter*ycenter) and k*k == (2*k*zcenter - zcenter*zcenter)){
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
  // (x - a)² + (y - b)² + (z - c)² = r²
  for(i=0;i<=nx;i++){ // (x - a)² = r² -> x² - 2xa + a² = r² -> x² = 2 * x * a - a * a
    for(j=0;j<=ny;j++){ // (y - b)² = r²
      for(k=0;k<=nz;k++){ // (z - c)² = r²
        if(i*i == (2*i*xcenter - xcenter*xcenter) and j*j == (2*j*ycenter - ycenter*ycenter) and k*k == (2*k*zcenter - zcenter*zcenter)){
          v[i][j][k].show = false;
        }
      }
    }
  }
}


