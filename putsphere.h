#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

/// @brief Classe para desenhar uma esfera, herda características de
/// FiguraGeometrica
/// @protected Raio da esfera
/// @public Construtor da classe para desenhar uma esfera e método herdado da
/// classe abstrata FiguraGeometrica
class PutSphere : public FiguraGeometrica {
   private:
    int radius;

   public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r,
              float g, float b, float a);
    ~PutSphere();
    virtual void draw(Sculptor &t);
};
#endif  // PUTSPHERE_H