#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"

/// @brief Classe para esconder uma elipsóide, herda características de FiguraGeometrica
/// @protected Raios da elipsóide
/// @public Método para esconder uma elipsóide e método abstrato herdado de FiguraGeometrica
class CutEllipsoid : public FiguraGeometrica {
   protected:
    int rx;
    int ry;
    int rz;

   public:
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    virtual void draw(Sculptor &t);
};
#endif  // CUTELLIPSOID_H