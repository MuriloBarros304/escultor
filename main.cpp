#include "sculptor.h"
#include "voxel.h"
#include "figurageometrica.h"
#include "cutvoxel.h"
#include "putvoxel.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "cutbox.h"
#include "putbox.h"

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
    Sculptor sculptor(10, 10, 10);
    FiguraGeometrica *p1 = new PutVoxel(5, 5, 5, 1.0, 0.0, 0.0, 1.0);
    p1->draw(sculptor);
    delete p1;
    
    FiguraGeometrica *p2 = new CutEllipsoid(5, 5, 5, 3, 3, 3);
    p2->draw(sculptor);
    delete p2;
    
    sculptor.writeOFF("output.off");
    return 0;
}