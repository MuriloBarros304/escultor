#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"

class CutBox : public FiguraGeometrica {
   protected:
    int x1, y1, z1;
   public:
    cutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    virtual void draw(Sculptor &t);
}
#endif // CUTBOX_H