#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

/// @brief Classe para desenhar uma caixa, herda características de
/// FiguraGeometrica
/// @protected Posições finais da caixa
/// @public Construtor de destrutor da classe para desenhar uma caixa e método
/// abstrato herdado de FiguraGeometrica
class PutBox : public FiguraGeometrica {
   protected:
    int x1, y1, z1;

   public:
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g,
           float b, float a);
    ~PutBox();
    virtual void draw(Sculptor &t);
};
#endif  // PUTBOX_H