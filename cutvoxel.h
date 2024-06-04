#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"

/// @brief Classe para esconder um voxel, herda características de
/// FiguraGeometrica
/// @public Construtor da classe para esconder um voxel e método herdado da
/// classe abstrata FiguraGeometrica
class CutVoxel : public FiguraGeometrica {
   public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel();
    virtual void draw(Sculptor &t);
};