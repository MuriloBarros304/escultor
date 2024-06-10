#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"

/// @brief Classe para desenhar um voxel, herda características de
/// FiguraGeometrica
/// @public Construtor e destrutor da classe para desenhar um voxel e
/// método herdado da classe abstrata FiguraGeometrica
class PutVoxel : public FiguraGeometrica {
   public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float a); // Construtor
    ~PutVoxel();                                                       // Destrutor
    virtual void draw(Sculptor &t);                                    // Método herdado de FiguraGeometrica
};
#endif  // CUTVOXEL_H