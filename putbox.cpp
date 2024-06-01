#include "putbox.h"

/// @brief Método para desenhar uma caixa
/// @param x0 Posição inicial da caixa no eixo x
/// @param x1 Posição final da caixa no eixo x
/// @param y0 Posição inicial da caixa no eixo y
/// @param y1 Posição final da caixa no eixo y
/// @param z0 Posição inicial da caixa no eixo z
/// @param z1 Posição final da caixa no eixo z
/// @param r Valor da cor vermelha
/// @param g Valor da cor verde
/// @param b Valor da cor azul
/// @param a Transparência
PutBox::putBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g,
               float b, float a) {
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->z0 = z0;
    this->z1 = z1;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

/// @brief Método da classe abstrata pura FiguraGeometrica
/// @param t Objeto da classe Sculptor
PutBox::draw(Sculptor &t) {
    int i, j, k;
    for (i = x0; i <= x1; i++) {
        for (j = y0; j <= y1; j++) {
            for (k = z0; k <= z1; k++) {
                t.setColor(r, g, b, a);
                t.putVoxel(i, j, k);
            }
        }
    }
}
