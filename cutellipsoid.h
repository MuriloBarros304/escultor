#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"

class CutEllipsoid : public FiguraGeometrica {
   private:
    int rx;
    int ry;
    int rz;
   public:
    cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    virtual void draw(Sculptor &t);
}
#endif // CUTELLIPSOID_H