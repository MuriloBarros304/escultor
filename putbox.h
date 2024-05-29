#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

class PutBox : public FiguraGeometrica {
   protected:
    int x1, y1, z1;
   public:
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    virtual void draw(Sculptor &t);
}
#endif // PUTBOX_H