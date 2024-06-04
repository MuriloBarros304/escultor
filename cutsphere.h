#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

/// @brief Classe para esconder uma esfera, herda características de
/// FiguraGeometrica
/// @protected Raio da esfera
/// @public Construtor da classe para esconder uma esfera e método herdado da
/// classe abstrata FiguraGeometrica
class CutSphere : public FiguraGeometrica {
   protected:
    int radius;

   public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere();
    virtual void draw(Sculptor &t);
};
#endif  // CUTSPHERE_H