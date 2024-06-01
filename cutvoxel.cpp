#include "cutvoxel.h"

/// @brief Método para desenhar um voxel
/// @param x Posição no eixo x
/// @param y Posição no eixo y
/// @param z Posição no eixo z
CutVoxel::cutVoxel (int x, int y, int z, float r, float g, float b, float a) {
    this->x0 = x;
    this->y0 = y;
    this->z0 = z;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a; 
}

/// @brief Método da classe abstrata pura FiguraGeometrica
/// @param t Objeto da classe Sculptor
CutVoxel::draw (Sculptor &t) {
    t.setColor(r, g, b, a);
    t.putVoxel(x0, y0, z0);
}