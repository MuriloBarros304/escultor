#include "putellipsoid.h"

/// @brief Método para desenhar uma elipsóide
/// @param xcenter Centro em no eixo x
/// @param ycenter Centro no eixo y
/// @param zcenter Centro no eixo z
/// @param rx Raio em x
/// @param ry Raio em y
/// @param rz Raio em z
/// @param r Valor da cor vermelha
/// @param g Valor da cor verde
/// @param b Valor da cor azul
/// @param a Transparência
void PutEllipsoid::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r,
                     float g, float b, float a) {
    this->x0 = xcenter;
    this->y0 = ycenter;
    this->z0 = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

/// @brief Método herdado da classe abstrata pura FiguraGeometrica
/// @param t Objeto da classe Sculptor
void PutEllipsoid::draw(Sculptor &t) {
    int i, j, k, xi, xf, yi, yf, zi, zf, rx2, ry2, rz2, dx, dy, dz;
    // (x - xc)² / rx² + (y - yc)² / ry² + (z - zc)² / rz² = 1
    // limites do elipsoide
    rx2 = rx * rx;
    ry2 = ry * ry;
    rz2 = rz * rz;
    xi = x0 - rx;
    xf = x0 + rx;
    yi = y0 - ry;
    yf = y0 + ry;
    zi = z0 - rz;
    zf = z0 + rz;
    for (i = xi; i <= xf; i++) {
        dx = (i - x0) * (i - x0);
        for (j = yi; j <= yf; j++) {
            dy = (j - y0) * (j - y0);
            for (k = zi; k <= zf; k++) {
                dz = (k - z0) * (k - z0);
                if ((dx / rx2 + dy / ry2 + dz / rz2) <= 1) {
                    t.setColor(r, g, b, a);
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}