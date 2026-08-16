#ifndef READTXT_H
#define READTXT_H
#include <vector>
#include <string>

#include "figurageometrica.h"

/// @brief Classe para ler o arquivo de comandos em formato TXT e alocar memória
/// para as figuras que têm seus endereços armazenados em um vetor de ponteiros
/// @private Tamanho da matriz, vetor de ponteiros para as figuras
/// @public Construtor e destrutor, função draw(), e funções para retornar
/// dimensões
class ReadTXT {
   private:
    int nx, ny, nz;
    std::vector<FiguraGeometrica*> vetor;
    std::vector<FiguraGeometrica*>::iterator it;

   public:
    ReadTXT();                      // Construtor vazio para modo interativo
    ReadTXT(const char* filename);  // Construtor
    ~ReadTXT();                     // Destrutor
    FiguraGeometrica* parseLine(std::string line); // Interpreta uma linha de comando
    void draw(Sculptor& t);         // Chama o método draw() herdado da classe
                                    // FiguraGeometrica para a figura desenhada
    int getX();                     // Retorna o tamanho em x da matriz
    int getY();                     // Retorna o tamanho em y da matriz
    int getZ();                     // Retorna o tamanho em z da matriz
};
#endif  // READTXT_H
