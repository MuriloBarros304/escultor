#include <vector>

#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"
#include "figurageometrica.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"
#include "sculptor.h"
#include "voxel.h"

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
    std::vector<FiguraGeometrica *> vetor;
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
    }

    sculptor.writeOFF("../../../output.off");
    return 0;
}