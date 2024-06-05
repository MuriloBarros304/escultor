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
    FiguraGeometrica *p; // verificar
    Sculptor sculptor(10, 10, 10);
    PutVoxel pv(5, 5, 5, 1.0, 0.0, 0.0, 1.0);
    pv.draw(sculptor);
    sculptor.writeOFF("output.off");
}