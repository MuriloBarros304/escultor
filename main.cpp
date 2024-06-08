#include <iostream>
#include "readtxt.h"

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
    ReadTXT teste("../../../input.txt");
    Sculptor figura(teste.getX(), teste.getY(), teste.getZ());
    std::cout << "lido: " << teste.getX() << ", " << teste.getY() << ", " << teste.getZ() << "\n";
    teste.draw(figura);
/*     std::vector<FiguraGeometrica *> vetor;
    Sculptor sculptor(10, 10, 10);

    FiguraGeometrica *p1 = new PutVoxel(1, 1, 1, 1.0, 0.0, 0.0, 1.0);
    p1->draw(sculptor);
    vetor.push_back(p1);

    FiguraGeometrica *p2 =
        new PutEllipsoid(5, 5, 5, 3, 3, 3, 0.0, 0.0, 1.0, 1.0);
    p2->draw(sculptor);
    vetor.push_back(p2);
    for (int i = 0; i < vetor.size(); i++) {
        delete vetor[i];
    } */

    figura.writeOFF("../../../output.off");
    return 0;
}