#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"

/// @brief Classe para esconder um voxel
/// @public Método para esconder um voxel e método herdado da classe abstrata FiguraGeometrica
class CutVoxel : public FiguraGeometrica {
    public: 
    cutVoxel (int x, int y, int z, float r, float g, float b, float a);
    virtual void draw (Sculptor &t);
}