#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"

/// @brief Classe para esconder uma caixa, herda de FiguraGeometrica
/// @protected Atributos exclusivos da classe: posição final da caixa
/// @public Método para cortar caixa e método herdado da classe abstrata FiguraGeometrica
class CutBox : public FiguraGeometrica {
   protected:
    int x1, y1, z1;

   public:
    cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    virtual void draw(Sculptor &t);
}
#endif  // CUTBOX_H