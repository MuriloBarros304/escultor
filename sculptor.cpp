#include "sculptor.h"

#include <fstream>
#include <iomanip>
#include <iostream>

#include "voxel.h"

/**
 * @brief Construtor da classe, recebe as coordenadas do tamanho da modelagem e
 * aloca memória para a criação de uma matriz de três dimensões
 * @param nx Número de voxels no eixo x
 * @param ny Número de voxels no eixo y
 * @param nz Número de voxels no eixo z
 */
Sculptor::Sculptor(int nx, int ny, int nz) {  // Construtor com argumentos
    this->nx = nx;
    this->ny = ny;
    this->nz = nz;
    int i, j;
    if (nx <= 0 or ny <= 0 or nz <= 0) {
        throw std::runtime_error("Erro nas dimensões da matriz\n");
    }
    // alocação dinâmica de memória
    v = new Voxel **[nx];
    v[0] = new Voxel *[nx * ny];
    v[0][0] = new Voxel[nx * ny * nz];
    // fixação dos ponteiros
    for (i = 0; i < nx; i++) {
        v[i] = v[0] + i * ny;  // fixar as linhas nos planos
        for (j = 0; j < ny; j++) {
            v[i][j] = v[0][0] + (i * ny + j) * nz;  // fixar as colunas
        }
    }
}

/**
 * @brief Destrutor da classe
 */
Sculptor::~Sculptor() {
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

/**
 * @brief Define a cor e transparência nos próximos comandos
 */
void Sculptor::setColor(float r, float g, float b, float a) {
    this->r = r;  // Red
    this->g = g;  // Green
    this->b = b;  // Blue
    this->a = a;  // Alpha
}

/**
 * @brief Adiciona um único voxel à escultura
 * @param x Endereço no eixo x
 * @param y Endereço no eixo y
 * @param z Endereço no eixo z
 * @warning É necessário ter uma cor definida anteriormente
 */
void Sculptor::putVoxel(int x, int y, int z) {
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    // std::cout<<"entrou em putVoxel"<<"\n";
}

/**
 * @brief Corta um voxel
 * @param x Endereço no eixo x
 * @param y Endereço no eixo y
 * @param z Endereço no eixo z
 */
void Sculptor::cutVoxel(int x, int y, int z) { v[x][y][z].show = false; }

/**
 * @brief Salva a matriz em formato .off
 * @param filename Nome do arquivo, exemplo: "output.off" para salvar no
 * diretório do projeto, ou adicionar caminho relativo
 */
void Sculptor::writeOFF(const char *filename) {
    int nVoxel = 0, f = 0, i, j, k;
    std::ofstream fout;

    // para diminuição do custo computacional, todos os voxels que estão
    // cobertos por outros voxels não devem ter show = true
    for (i = 1; i < nx - 1; i++) {
        for (j = 1; j < ny - 1; j++) {
            for (k = 1; k < nz - 1; k++) {
                if (v[i][j][k].show and v[i][j + 1][k].show and
                    v[i][j][k - 1].show and v[i - 1][j][k].show and
                    v[i][j][k + 1].show and v[i][j - 1][k].show and
                    v[i + 1][j][k].show) {
                    v[i][j][k].show = false;
                }
            }
        }
    }

    // contagem de voxels
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            for (k = 0; k < nz; k++) {
                if (v[i][j][k].show == true) {
                    nVoxel++;
                }
            }
        }
    }

    // abrir arquivo
    fout.open(filename);
    if (!fout.is_open()) {
        throw std::runtime_error("Erro ao tentar abrir o arquivo \n");
    }
    // escrever no arquivo
    fout << "OFF\n";
    fout << 8 * nVoxel << " " << 6 * nVoxel << " " << 0 << "\n";
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            for (k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                    fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                    fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                    fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                }
            }
        }
    }
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            for (k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    fout << 4 << " " << 0 + f << " " << 3 + f << " " << 2 + f
                         << " " << 1 + f << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << "\n";
                    fout << 4 << " " << 4 + f << " " << 5 + f << " " << 6 + f
                         << " " << 7 + f << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << "\n";
                    fout << 4 << " " << 0 + f << " " << 1 + f << " " << 5 + f
                         << " " << 4 + f << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << "\n";
                    fout << 4 << " " << 0 + f << " " << 4 + f << " " << 7 + f
                         << " " << 3 + f << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << "\n";
                    fout << 4 << " " << 3 + f << " " << 7 + f << " " << 6 + f
                         << " " << 2 + f << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << "\n";
                    fout << 4 << " " << 1 + f << " " << 2 + f << " " << 6 + f
                         << " " << 5 + f << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " "
                         << v[i][j][k].a << "\n";
                    f += 8;
                }
            }
        }
    }
    std::cout << "Arquivo de saída salvo\n";
    fout.close();
}
