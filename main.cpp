#include <iostream>
#include "readtxt.h"
#include "putellipsoid.h"
#include "putvoxel.h"

/**
 * \mainpage
 * @brief Escultor 3D utilizando blocos com C++, projeto requerido na segunda
 * unidade da disciplina: Programação Avançada no Departamento de Engenharia de
 * Computação e Automação da Universidade Federal do Rio Grande do Norte.
 * \authors
 * Murilo de Lima Barros \n
 * Leonardo Pessoa Cavalcanti
 */
int main(void) {
         
    ReadTXT arquivo("../../../input.txt");
    Sculptor figura(arquivo.getX(), arquivo.getY(), arquivo.getZ());
    arquivo.draw(figura);
    figura.writeOFF("../../../output.off");
    /*
    std::vector<FiguraGeometrica *> vetor;
    Sculptor sculptor(10, 10, 10);
    FiguraGeometrica *p1 = new PutVoxel(1, 1, 1, 1.0, 0.0, 0.0, 1.0);
    p1->draw(sculptor);
    delete p1;
    FiguraGeometrica *p2 = new PutEllipsoid(5, 5, 5, 3, 3, 3, 0.0, 0.0, 1.0, 1.0);
    p2->draw(sculptor);
    delete p2;
    vetor.push_back(p2);
    sculptor.writeOFF("../../../output.off"); */
    return 0;
}