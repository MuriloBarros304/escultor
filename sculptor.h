#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"

class Sculptor {
   public:
    Voxel*** v;                           // Matriz 3D
    int nx, ny, nz;                       // Dimensões
    float r, g, b, a;                     // Cor atual de desenho
    Sculptor(int _nx, int _ny, int _nz);  // Construtor com argumentos
    ~Sculptor();                          // Destrutor
    void setColor(float _r, float _g, float _b, float _a);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(const char* filename);
};

#endif  // SCULPTOR_H