#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

/// @brief Classe para desenhar uma esfera, herda características de FiguraGeometrica
/// @protected Raio da esfera
/// @public Método para desenhar uma esfera e método herdado da classe abstrata FiguraGeometrica
class PutSphere : public FiguraGeometrica {
   private:
    int radius;
   public:
    void putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    virtual void draw(Sculptor &t);
};
#endif // PUTSPHERE_H