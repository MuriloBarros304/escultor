#include "cutvoxel.h"

/// @brief Construtor da classe para desenhar um voxel
/// @param x Posição no eixo x
/// @param y Posição no eixo y
/// @param z Posição no eixo z
CutVoxel::CutVoxel(int x, int y, int z) {
    this->x0 = x;
    this->y0 = y;
    this->z0 = z;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

/// @brief Destrutor da classe
CutVoxel::~CutVoxel() {}

/// @brief Método da classe abstrata pura FiguraGeometrica
/// @param t Objeto da classe Sculptor
void CutVoxel::draw(Sculptor &t) { t.putVoxel(x0, y0, z0); }