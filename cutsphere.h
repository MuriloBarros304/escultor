#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

/// @brief Classe para esconder uma esfera
/// @protected Raio da esfera
/// @public Método para esconder uma esfera
class CutSphere : public FiguraGeometrica {
   protected:
    int radius;
   public:
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    virtual void draw(Sculptor &t);
}
#endif // CUTSPHERE_H