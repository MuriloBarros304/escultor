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
    ReadTXT arquivo("../../../input.txt");
    Sculptor figura(arquivo.getX(), arquivo.getY(), arquivo.getZ());
    arquivo.draw(figura);
    figura.writeOFF("../../../output.off");
    return 0;
}