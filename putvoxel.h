#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"

class PutVoxel : public FiguraGeometrica {
    public: 
    putVoxel (int x, int y, int z, float r, float g, float b, float a);
    virtual void draw (Sculptor &t);
}