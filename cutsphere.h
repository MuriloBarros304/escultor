#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

class CutSphere : public FiguraGeometrica {
   private:
    int radius;
   public:
    cutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    virtual void draw(Sculptor &t);
}
#endif // CUTSPHERE_H