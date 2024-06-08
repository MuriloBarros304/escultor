#ifndef READTXT_H
#define READTXT_H
#include <string>
#include <vector>
#include "figurageometrica.h"

class ReadTXT {
   private:
    int nx, ny, nz;
    std::vector<FiguraGeometrica*> vetor;
    std::vector<FiguraGeometrica*>::iterator itf;
   public:
    ReadTXT(const char* filename);
    ~ReadTXT();
    void draw(Sculptor &t);
    int getX();
    int getY();
    int getZ();
};
#endif // READTXT_H
