#include "putvoxel.h"

#include <iostream>

/// @brief Construtor da classe para desenhar um voxel
/// @param x Posição no eixo x
/// @param y Posição no eixo y
/// @param z Posição no eixo z
/// @param r Valor da cor vermelha
/// @param g Valor da cor verde
/// @param b Valor da cor azul
/// @param a Transparência
PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a) {
    this->x0 = x;
    this->y0 = y;
    this->z0 = z;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutVoxel::~PutVoxel() {}

/// @brief Método da classe abstrata pura FiguraGeometrica
/// @param t Objeto da classe Sculptor
void PutVoxel::draw(Sculptor &t) {
    t.setColor(r, g, b, a);
    t.putVoxel(x0, y0, z0);
}