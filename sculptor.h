#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"

class Sculptor {
private:
  Voxel ***v; // Matriz 3D 
  int nx,ny,nz; // Dimensões
  float r,g,b,a; // Cor atual de desenho
public:
  Sculptor(int _nx, int _ny, int _nz); // Construtor com argumentos
  ~Sculptor(); // Destrutor
  void setColor(float _r, float _g, float _b, float _a);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(const char* filename);
};

#endif // SCULPTOR_H