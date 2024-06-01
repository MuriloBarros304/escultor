#include "cutellipsoid.h"

/// @brief Método para esconder uma elipsóide
/// @param xcenter Centro em no eixo x
/// @param ycenter Centro no eixo y
/// @param zcenter Centro no eixo z
/// @param rx Raio em x
/// @param ry Raio em y
/// @param rz Raio em z
CutEllipsoid::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    this->x0 = xcenter;
    this->y0 = ycenter;
    this->z0 = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}

/// @brief Método da classe abstrata pura FiguraGeometrica
/// @param t Objeto da classe Sculptor
void CutEllipsoid::draw(Sculptor &t) {
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
        dx = (i - xcenter) * (i - xcenter);
        for (j = yi; j <= yf; j++) {
            dy = (j - ycenter) * (j - ycenter);
            for (k = zi; k <= zf; k++) {
                dz = (k - zcenter) * (k - zcenter);
                if ((dx / rx2 + dy / ry2 + dz / rz2) <= 1) {
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}