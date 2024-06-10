#include "readtxt.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"

/// @brief Construtor da classe, lê o arquivo de entrada e aloca figuras e
/// cortes no vetor de ponteiros
/// @param filename Nome do arquivo, exemplo: "input.off" para salvar no
/// diretório do projeto, ou adicionar caminho relativo
ReadTXT::ReadTXT(const char* filename) {
    std::ifstream fin;
    std::string s;

    fin.open(filename);
    if (!fin.is_open()) {
        std::cerr << "Impossível encontrar o arquivo: " << filename
                  << std::endl;
        exit(1);
    }
    while (fin.good()) {
        fin >> s;
        if (s.compare("dim") == 0) {
            int x, y, z;
            fin >> x >> y >> z;
            nx = x;
            ny = y;
            nz = z;
            std::cout << "Dimensões lidas: " << nx << ", " << ny << ", "
                        << nz << "\n";
        } else if (s.compare("putvoxel") == 0) {
            int x0, y0, z0;
            float r, g, b, a;
            fin >> x0 >> y0 >> z0;
            fin >> r >> g >> b >> a;
            vetor.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
        } else if (s.compare("cutvoxel") == 0) {
            int x0, y0, z0;
            fin >> x0 >> y0 >> z0;
            vetor.push_back(new CutVoxel(x0, y0, z0));
        } else if (s.compare("putbox") == 0) {
            int x0, y0, z0, x1, y1, z1;
            float r, g, b, a;
            fin >> x0 >> x1 >> y0;
            fin >> y1 >> z0 >> z1;
            fin >> r >> g >> b >> a;
            vetor.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        } else if (s.compare("cutbox") == 0) {
            int x0, y0, z0, x1, y1, z1;
            float r, g, b, a;
            fin >> x0 >> x1 >> y0;
            fin >> y1 >> z0 >> z1;
            vetor.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        } else if (s.compare("putsphere") == 0) {
            int xcenter, ycenter, zcenter, radius;
            float r, g, b, a;
            fin >> xcenter >> ycenter >> zcenter >> radius;
            fin >> r >> g >> b >> a;
            vetor.push_back(new PutSphere(xcenter, ycenter, zcenter, radius,
                                            r, g, b, a));
        } else if (s.compare("cutsphere") == 0) {
            int xcenter, ycenter, zcenter, radius;
            float r, g, b, a;
            fin >> xcenter >> ycenter >> zcenter >> radius;
            vetor.push_back(
                new CutSphere(xcenter, ycenter, zcenter, radius));
        } else if (s.compare("putellipsoid") == 0) {
            int xcenter, ycenter, zcenter, rx, ry, rz;
            float r, g, b, a;
            fin >> xcenter >> ycenter >> zcenter;
            fin >> rx >> ry >> rz;
            fin >> r >> g >> b >> a;
            vetor.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx,
                                                ry, rz, r, g, b, a));
        } else if (s.compare("cutellipsoid") == 0) {
            int xcenter, ycenter, zcenter, rx, ry, rz;
            float r, g, b, a;
            fin >> xcenter >> ycenter >> zcenter;
            fin >> rx >> ry >> rz;
            vetor.push_back(
                new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
        }
    }
    std::cout << "Arquivo de entrada lido\n";
    fin.close();
    if (vetor.empty()) {
        std::cout << "O vetor de figuras geométricas está vazio\n";
    } else {
        std::cout << "O vetor de figuras geométricas foi preenchido corretamente\n";
    }
}

/// @brief Destrutor, libera memória alocada
ReadTXT::~ReadTXT() {
    for (it = vetor.begin(); it != vetor.end(); it++) {
        delete *it;
    }
}

/// @brief Método para utilizar o draw() no vetor de ponteiros para figuras da
/// classe FiguraGeometrica
/// @param t Figura do tipo Sculptor
void ReadTXT::draw(Sculptor& t) {
    for (auto it : vetor) {
        it->draw(t);
    }
}

/// @brief Método para adquirir dimensão x da escultura
/// @return Dimensão x
int ReadTXT::getX() { return nx; }

/// @brief Método para adquirir dimensão y da escultura
/// @return Dimensão y
int ReadTXT::getY() { return ny; }

/// @brief Método para adquirir dimensão z da escultura
/// @return Dimensão z
int ReadTXT::getZ() { return nz; }
