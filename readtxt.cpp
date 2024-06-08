#include "readtxt.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include <fstream>
#include <iostream>
#include <vector>

ReadTXT::ReadTXT(const char* filename) {
std::ifstream fin;
    std::string s;
    std::vector<FiguraGeometrica *> vetor;

    fin.open(filename);
    if (!fin.is_open()) {
        std::cerr << "Impossível encontrar o arquivo: " << filename << std::endl;
        exit(1);
    }
    while (fin.good()) {
        fin >> s;
        if (fin.good()) {
            if (s.compare("dim") == 0) {
                int x, y, z;
                fin >> x >> y >> z;
                nx = x;
                ny = y;
                nz = z;
            }
            if (s.compare("putvoxel") == 0) {
                int x0, y0, z0;
                float r, g, b, a;
                fin >> x0 >> y0 >> z0;
                fin >> r >> g >> b >> a;
                vetor.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
            }
            if (s.compare("putellipsoid") == 0) {
                int xcenter, ycenter, zcenter, rx, ry, rz;
                float r, g, b, a;
                fin >> xcenter >> ycenter >> zcenter;
                fin >> rx >> ry >> rz;
                fin >> r >> g >> b >> a;
                vetor.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
            }
        }
    }
    fin.close();
}

ReadTXT::~ReadTXT() {
    for(itf = vetor.begin(); itf != vetor.end(); itf++){
        delete *itf;
      }
}

void ReadTXT::draw(Sculptor &t) {
    for (auto it: vetor){
        it->draw(t);
    }
}

int ReadTXT::getX() {
    return nx;
}

int ReadTXT::getY() {
    return ny;
}

int ReadTXT::getZ() {
    return nz;
}
