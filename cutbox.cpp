#include "cutbox.h"

/// @brief Construtor da classe para esconder uma caixa
/// @param x0 Posição inicial da caixa no eixo x
/// @param x1 Posição final da caixa no eixo x
/// @param y0 Posição inicial da caixa no eixo y
/// @param y1 Posição final da caixa no eixo y
/// @param z0 Posição inicial da caixa no eixo z
/// @param z1 Posição final da caixa no eixo z
CutBox::CutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->z0 = z0;
    this->z1 = z1;
}

CutBox::~CutBox() {}

/// @brief Método da classe abstrata pura FiguraGeometrica
/// @param t Objeto da classe Sculptor
void CutBox::draw(Sculptor &t) {
    int i, j, k;
    for (i = x0; i <= x1; i++) {
        for (j = y0; j <= y1; j++) {
            for (k = z0; k <= z1; k++) {
                t.cutVoxel(i, j, k);
            }
        }
    }
}
