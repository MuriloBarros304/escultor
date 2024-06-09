#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"

/// @brief Classe dos objetos que serão desenhados
/// @public Métodos para desenhar, esconder, alocar e escrever
class Sculptor {
   public:
    Voxel*** v;                           // Matriz 3D
    int nx, ny, nz;                       // Dimensões
    float r, g, b, a;                     // Cor e transparência atual de desenho
    Sculptor(int nx, int ny, int nz);  // Construtor com argumentos
    ~Sculptor();                          // Destrutor
    void setColor(float r, float g, float b, float a);             // Método para alterar cor
    void putVoxel(int x, int y, int z);   // Método para desenhar um voxel
    void cutVoxel(int x, int y, int z);   // Método para esconder um voxel
    void writeOFF(const char* filename);
};

#endif  // SCULPTOR_H