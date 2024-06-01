#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

/// @brief Classe abstrata pura que passa por herança o método draw() e os
/// atributos de uma figura genérica
class FiguraGeometrica {
   protected:
    int x0, y0, z0;
    float r, g, b, a;

   public:
    FiguraGeometrica();
    ~FiguraGeometrica();
    virtual void draw(Sculptor &t) = 0;
};

#endif  // FIGURAGEOMETRICA_H