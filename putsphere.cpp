#include "putsphere.h"

/// @brief Método para criar uma esfera
/// @param xcenter Centro no eixo x
/// @param ycenter Centro no eixo y
/// @param zcenter Centro no eixo z
/// @param radius Raio 
/// @param r Valor da cor vermelha
/// @param g Valor da cor verde
/// @param b Valor da cor azul
/// @param a Transparência
PutSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius, float r,
                     float g, float b, float a) {
    this->x0 = xcenter;
    this->y0 = ycenter;
    this->z0 = zcenter;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

/// @brief Método da classe abstrata pura FiguraGeometrica
/// @param t Objeto da classe Sculptor
void PutSphere::draw(Sculptor &t) {
    int i, j, k, xi, xf, yi, yf, zi, zf, dx, dy, dz, r2;
    // (x - a)² + (y - b)² + (z - c)² = r²
    // limites da esfera
    r2 = radius * radius;
    xi = x0 - radius;
    xf = x0 + radius;
    yi = y0 - radius;
    yf = y0 + radius;
    zi = z0 - radius;
    zf = z0 + radius;
    for (i = xi; i <= xf; i++) {
        dx = i - xcenter * (i - xcenter);
        for (j = yi; j <= yf; j++) {
            dy = (j - ycenter) * (j - ycenter);
            for (k = zi; k <= zf; k++) {
                dz = (k - zcenter) * (k - zcenter);
                if (dx + dy + dz <= r2) {
                    t.setColor(r, g, b, a);
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}