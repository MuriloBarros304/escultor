#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"

/// @brief Classe para desenhar uma elipsóide, herda características de
/// FiguraGeometrica
/// @protected Raios da elipsóide
/// @public Construtor da classe para desenhar elipsoide e método herdado da
/// classe abstrata FiguraGeometrica
class PutEllipsoid : public FiguraGeometrica {
   protected:
    int rx;
    int ry;
    int rz;

   public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz,
                 float r, float g, float b, float a);
    ~PutEllipsoid();
    virtual void draw(Sculptor &t);
};
#endif  // PUTELLIPSOID_H