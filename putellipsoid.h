#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"

class PutEllipsoid : public FiguraGeometrica {
   private:
    int rx;
    int ry;
    int rz;
   public:
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    virtual void draw(Sculptor &t);
}
#endif // PUTELLIPSOID_H