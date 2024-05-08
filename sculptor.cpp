#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Sculptor::Sculptor(int _nx, int _ny, int _nz){ // Construtor com argumentos
  nx = _nx;
  ny = _ny;
  nz = _nz;
  int i, j;
  if(nx <= 0 or ny <=0 or nz <=0){
    throw std::runtime_error("Erro nas dimensões da matriz\n");
  }
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
  int i, j, k, x0, x1, y0, y1, z0, z1, dx, dy, dz;
   // (x - a)² + (y - b)² + (z - c)² = r²
   // limites da esfera
  x0 = xcenter-radius; 
  x1 = xcenter+radius;
  y0 = ycenter-radius;
  y1 = ycenter+radius;
  z0 = zcenter-radius;
  z1 = zcenter+radius;
  for(i=(x0); i<=(x1); i++){
    dx = (i-xcenter)*(i-xcenter);   
      for(j=(y0); j<=(y1); j++){
        dy = (j-ycenter)*(j-ycenter);
          for(k=(z0); k<=(z1); k++){
            dz = (k-zcenter)*(k-zcenter);
            if(dx + dy + dz <= (radius*radius)){
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
  int i, j, k, x0, x1, y0, y1, z0, z1, dx, dy, dz;
   // (x - a)² + (y - b)² + (z - c)² = r²
   // limites da esfera
  x0 = xcenter-radius; 
  x1 = xcenter+radius;
  y0 = ycenter-radius;
  y1 = ycenter+radius;
  z0 = zcenter-radius;
  z1 = zcenter+radius;
  for(i=(x0); i<=(x1); i++){
    dx = (i-xcenter)*(i-xcenter);   
      for(j=(y0); j<=(y1); j++){
        dy = (j-ycenter)*(j-ycenter);
          for(k=(z0); k<=(z1); k++){
            dz = (k-zcenter)*(k-zcenter);
            if(dx + dy + dz <= (radius*radius)){
              v[i][j][k].show = false;
        }
      }
    }
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
  int i, j, k, x0, x1, y0, y1, z0, z1;
  double dx, dy, dz;
  // (x - xc)² / rx² + (y - yc)² / ry² + (z - zc)² / rz² = 1
  // limites do elipsoide
  x0 = xcenter - rx; 
  x1 = xcenter + rx;
  y0 = ycenter - ry;
  y1 = ycenter + ry;
  z0 = zcenter - rz;
  z1 = zcenter + rz;
  for (i = x0; i <= x1; i++) {
    dx = (i - xcenter) * (i - xcenter);
    for (j = y0; j <= y1; j++) {
      dy = (j - ycenter) * (j - ycenter);
      for (k = z0; k <= z1; k++) { 
        dz = (k - zcenter) * (k - zcenter);
        if ((dx / (rx * rx) + dy / (ry * ry) + dz / (rz * rz)) <= 1) {
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

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
  int i, j, k, x0, x1, y0, y1, z0, z1;
  double dx, dy, dz;
  // (x - xc)² / rx² + (y - yc)² / ry² + (z - zc)² / rz² = 1
  // limites do elipsoide
  x0 = xcenter - rx; 
  x1 = xcenter + rx;
  y0 = ycenter - ry;
  y1 = ycenter + ry;
  z0 = zcenter - rz;
  z1 = zcenter + rz;
  for (i = x0; i <= x1; i++) {
    dx = (i - xcenter) * (i - xcenter);
    for (j = y0; j <= y1; j++) {
      dy = (j - ycenter) * (j - ycenter);
      for (k = z0; k <= z1; k++) { 
        dz = (k - zcenter) * (k - zcenter);
        if ((dx / (rx * rx) + dy / (ry * ry) + dz / (rz * rz)) <= 1) {
          v[i][j][k].show = false;
        }
      }
    }
  }
}

void Sculptor::writeOFF(const char *filename){
  int nVoxel = 0, f = 0, i, j, k;
  std::ofstream fout;

  // contagem de voxels
  for(i=0;i<nx;i++){
    for(j=0;j<ny;j++){
      for(k=0;k<nz;k++){
        if(v[i][j][k].show == true){
          nVoxel++;
        }
      }
    }
  }
  // abrir arquivo
  fout.open(filename);
  if (!fout.is_open()) {
    throw std::runtime_error("Erro ao tentar abrir o arquivo \n");
  }
  // escrever no arquivo
  fout << "OFF\n";
  fout << 8 * nVoxel << " " << 6 * nVoxel << " " << 0 << "\n";
  for(i=0;i<nx;i++){
    for(j=0;j<ny;j++){
      for(k=0;k<nz;k++){
        if(v[i][j][k].show){
          fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n"; 
          fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n"; 
          fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n"; 
          fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n"; 
          fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n"; 
          fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n"; 
          fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n"; 
          fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n"; 
        }
      }
    }
  }
  for(i=0;i<nx;i++){
    for(j=0;j<ny;j++){
      for(k=0;k<nz;k++){
        if(v[i][j][k].show){ 
          fout << 4 << " " << 0 + f << " " << 3 + f << " " << 2 + f << " " << 1 + f << " " << 
          v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
          fout << 4 << " " << 4 + f << " " << 5 + f << " " << 6 + f << " " << 7 + f << " " << 
          v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
          fout << 4 << " " << 0 + f << " " << 1 + f << " " << 5 + f << " " << 4 + f << " " << 
          v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
          fout << 4 << " " << 0 + f << " " << 4 + f << " " << 7 + f << " " << 3 + f << " " << 
          v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
          fout << 4 << " " << 3 + f << " " << 7 + f << " " << 6 + f << " " << 2 + f << " " << 
          v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
          fout << 4 << " " << 1 + f << " " << 2 + f << " " << 6 + f << " " << 5 + f << " " << 
          v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
          f += 8;
        }
      }
    }
  }
std::cout << "Arquivo salvo\n";
fout.close();
}
    