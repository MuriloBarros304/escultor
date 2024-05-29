#include "putsphere.h"

PutSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a) {
    this->x = xcenter;
    this->y = ycenter;
    this->z = zcenter;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutSphere::draw(Sculptor &t) {
    int i, j, k, x0, x1, y0, y1, z0, z1, dx, dy, dz;
    // (x - a)² + (y - b)² + (z - c)² = r²
    // limites da esfera
    r2 = radius * radius;
    x0 = xcenter - radius;
    x1 = xcenter + radius;
    y0 = ycenter - radius;
    y1 = ycenter + radius;
    z0 = zcenter - radius;
    z1 = zcenter + radius;
    for (i = x0; i <= x1; i++) {
        dx = i - xcenter * (i - xcenter);
        for (j = y0; j <= y1; j++) {
            dy = (j - ycenter) * (j - ycenter);
            for (k = z0; k <= z1; k++) {
                dz = (k - zcenter) * (k - zcenter);
                if (dx + dy + dz <= r2) {
                    t.setColor(r, g, b, a);
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}