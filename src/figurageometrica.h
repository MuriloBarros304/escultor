#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

/// @brief Classe abstrata pura que passa por herança o método draw() e os
/// atributos de uma figura genérica
/// @protected Posição e cor
/// @public Construtor, destrutor e método herdado da classe abstrata
/// FiguraGeometrica
class FiguraGeometrica {
   protected:
    int x0, y0, z0;    // Posição
    float r, g, b, a;  // Cor

   public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(Sculptor &t) = 0;
};

#endif  // FIGURAGEOMETRICA_H