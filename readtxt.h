#ifndef READTXT_H
#define READTXT_H
#include <string>
#include <vector>

#include "figurageometrica.h"

/// @brief Classe para ler o arquivo de comandos em formato TXT
/// @private Tamanho da matriz, vetor de ponteiros para as figuras
/// @public Construtor e destrutor, função draw(), e funções para retornar
/// dimensões
class ReadTXT {
   private:
    int nx, ny, nz;
    std::vector<FiguraGeometrica*> vetor;
    std::vector<FiguraGeometrica*>::iterator it;

   public:
    ReadTXT(const char* filename);
    ~ReadTXT();
    void draw(Sculptor& t);
    int getX();
    int getY();
    int getZ();
};
#endif  // READTXT_H
