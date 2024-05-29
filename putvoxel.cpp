#include "putvoxel.h"

PutVoxel::putVoxel (int x, int y, int z, float r, float g, float b, float a) {
    this->x0 = x;
    this->y0 = y;
    this->z0 = z;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a; 
}

PutVoxel::draw (Sculptor &t) {
    t.setColor(r, g, b, a);
    t.putVoxel(x0, y0, z0);
}