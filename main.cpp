#include "sculptor.h"

/**
 * \mainpage
 * @brief Escultor 3D utilizando blocos com C++, projeto requerido na segunda
 * unidade da disciplina: Programação Avançada no Departamento de Engenharia de
 * Computação e Automação da Universidade Federal do Rio Grande do Norte.
 * \authors
 * Murilo de Lima Barros \n
 * Leonardo Pessoa Cavalcanti
 */
int main(void) {  // Modelagem de um quarto
    Sculptor quarto(100, 100, 100);
    quarto.setColor(1.0, 1.0, 1.0, 1);  // paredes
    quarto.putBox(0, 99, 0, 99, 0, 99);
    quarto.cutBox(2, 97, 1, 99, 2, 99);
    quarto.setColor(0.99, 0.99, 0.10, 1);
    quarto.putBox(2, 12, 42, 58, 48, 64);  // estantes
    quarto.cutBox(3, 13, 43, 57, 49, 63);
    quarto.putBox(2, 12, 58, 74, 64, 80);
    quarto.cutBox(3, 13, 59, 73, 65, 79);
    quarto.putBox(2, 12, 26, 42, 32, 48);
    quarto.cutBox(3, 13, 27, 41, 33, 47);
    quarto.setColor(0.39, 0.18, 0.01, 1);  // janela
    quarto.putBox(34, 68, 34, 68, 0, 3);
    quarto.setColor(0.4, 0.4, 0.9, 0.3);  // transparencia na janela de vidro
    quarto.cutBox(36, 50, 36, 50, 0, 3);
    quarto.cutBox(36, 50, 52, 66, 0, 3);
    quarto.cutBox(52, 66, 52, 66, 0, 3);
    quarto.cutBox(52, 66, 36, 50, 0, 3);
    quarto.putBox(36, 50, 36, 50, 2, 2);
    quarto.putBox(36, 50, 52, 66, 2, 2);
    quarto.putBox(52, 66, 52, 66, 2, 2);
    quarto.putBox(52, 66, 36, 50, 2, 2);
    quarto.setColor(0.39, 0.18, 0.01, 1);  // cama
    quarto.putBox(30, 97, 10, 14, 2, 30);
    quarto.putBox(97, 97, 14, 28, 2, 30);
    quarto.putBox(97, 97, 28, 29, 3, 29);
    quarto.putBox(30, 34, 2, 9, 26, 30);
    quarto.putBox(30, 34, 2, 9, 3, 7);
    quarto.putBox(93, 97, 2, 9, 3, 7);
    quarto.putBox(93, 97, 2, 9, 26, 30);
    quarto.setColor(0.9, 0.6, 0.1, 1);
    quarto.putBox(31, 96, 14, 20, 3, 29);
    quarto.setColor(0.9, 0.9, 0.9, 1);
    quarto.putBox(86, 96, 21, 23, 4, 28);
    quarto.setColor(0.39, 0.18, 0.01, 1);  // escrivaninha
    quarto.putBox(77, 97, 30, 32, 50, 90);
    quarto.putBox(77, 79, 2, 29, 50, 52);
    quarto.putBox(77, 79, 2, 29, 88, 90);
    quarto.putBox(95, 97, 2, 29, 88, 90);
    quarto.putBox(95, 97, 2, 29, 50, 52);
    quarto.setColor(0.20, 0.4, 0.9, 1);  // cadeira
    quarto.putBox(75, 90, 15, 17, 53, 68);
    quarto.putBox(75, 76, 16, 36, 53, 68);
    quarto.putBox(75, 77, 2, 15, 53, 55);
    quarto.putBox(75, 77, 2, 15, 66, 68);
    quarto.putBox(88, 90, 2, 15, 53, 55);
    quarto.putBox(88, 90, 2, 15, 66, 68);
    quarto.setColor(0.9, 0.9, 0.9, 1);  // papel
    quarto.putBox(78, 90, 33, 33, 80, 89);
    quarto.setColor(0.1, 0.1, 0.1, 1);  // lapis
    quarto.putBox(79, 83, 34, 34, 81, 81);
    quarto.setColor(0.1, 0.1, 0.1, 1);  // notebook
    quarto.putBox(78, 88, 33, 33, 52, 69);
    quarto.putBox(88, 88, 33, 43, 52, 69);
    quarto.setColor(0.9, 0.1, 0.1, 1);  // livros
    quarto.putBox(3, 11, 43, 56, 50, 50);
    quarto.putBox(3, 11, 43, 57, 54, 54);
    quarto.putBox(3, 11, 59, 73, 67, 67);
    quarto.putBox(3, 11, 59, 72, 78, 78);
    quarto.putBox(3, 11, 27, 40, 34, 34);
    quarto.putBox(3, 11, 27, 41, 40, 40);
    quarto.setColor(0.9, 0.8, 0.3, 1);
    quarto.putBox(3, 11, 27, 40, 35, 35);
    quarto.putBox(3, 11, 27, 41, 45, 45);
    quarto.putBox(3, 11, 43, 56, 51, 51);
    quarto.putBox(3, 11, 43, 56, 60, 60);
    quarto.putBox(3, 11, 43, 56, 53, 53);
    quarto.putBox(3, 11, 59, 72, 73, 73);
    quarto.putBox(3, 11, 59, 72, 70, 70);
    quarto.setColor(0.2, 0.12, 0.35, 1);
    quarto.putBox(3, 11, 27, 40, 37, 38);
    quarto.putBox(3, 11, 27, 40, 42, 42);
    quarto.putBox(3, 11, 59, 72, 69, 69);
    quarto.putBox(3, 11, 43, 56, 52, 52);
    quarto.putBox(3, 11, 43, 56, 61, 61);
    quarto.putBox(3, 11, 43, 56, 55, 55);
    quarto.putBox(3, 11, 59, 72, 71, 71);
    quarto.setColor(0.1, 0.64, 0.1, 1);
    quarto.putBox(3, 11, 27, 36, 39, 39);
    quarto.putBox(3, 11, 27, 36, 36, 36);
    quarto.putBox(3, 11, 27, 40, 43, 44);
    quarto.putBox(3, 11, 59, 70, 65, 65);
    quarto.putBox(3, 11, 43, 56, 56, 56);
    quarto.putBox(3, 11, 43, 56, 62, 62);
    quarto.putBox(3, 11, 59, 73, 72, 72);
    quarto.setColor(0.9, 0.8, 0.7, 1);  // piso
    quarto.putBox(2, 97, 1, 1, 2, 99);
    quarto.setColor(0.1, 0.1, 0.1, 1);
    quarto.putBox(2, 97, 1, 1, 80, 80);
    quarto.putBox(2, 97, 1, 1, 60, 60);
    quarto.putBox(2, 97, 1, 1, 40, 40);
    quarto.putBox(2, 97, 1, 1, 20, 20);
    quarto.putBox(80, 80, 1, 1, 2, 99);
    quarto.putBox(60, 60, 1, 1, 2, 99);
    quarto.putBox(40, 40, 1, 1, 2, 99);
    quarto.putBox(20, 20, 1, 1, 2, 99);
    quarto.setColor(0.55, 0.35, 0.1, 1);  // gavetas
    quarto.putBox(2, 20, 2, 37, 60, 96);
    quarto.cutBox(20, 20, 2, 37, 95, 95);
    quarto.cutBox(20, 20, 2, 37, 61, 61);
    quarto.cutBox(20, 20, 27, 27, 62, 94);
    quarto.cutBox(20, 20, 17, 17, 62, 94);
    quarto.cutBox(20, 20, 7, 7, 62, 94);
    quarto.cutBox(10, 20, 3, 7, 63, 93);  // gaveta aberta
    quarto.putBox(20, 29, 2, 2, 62, 94);
    quarto.putBox(30, 30, 2, 7, 62, 94);
    quarto.putBox(10, 29, 2, 6, 62, 62);
    quarto.putBox(10, 29, 2, 6, 94, 94);
    quarto.setColor(0.4, 0.2, 0.1, 1);
    quarto.putBox(19, 19, 2, 37, 95, 95);
    quarto.putBox(19, 19, 2, 37, 61, 61);
    quarto.putBox(19, 19, 27, 27, 62, 94);
    quarto.putBox(19, 19, 17, 17, 62, 94);
    quarto.putBox(19, 19, 36, 36, 62, 94);
    quarto.putBox(19, 19, 7, 7, 62, 94);
    quarto.setColor(0.1, 0.1, 0.1, 1);
    quarto.putBox(21, 21, 32, 32, 77, 79);
    quarto.putBox(21, 21, 22, 22, 77, 79);
    quarto.putBox(21, 21, 12, 12, 77, 79);
    quarto.putBox(31, 31, 4, 4, 77, 79);
    quarto.cutBox(19, 19, 37, 37, 61, 95);
    quarto.cutBox(20, 20, 3, 7, 63, 93);
    quarto.setColor(0.85, 0.1, 0.23, 1);  // roupas
    quarto.putBox(14, 28, 4, 4, 63, 75);
    quarto.setColor(0.9, 0.53, 0.01, 1);
    quarto.putBox(14, 28, 6, 6, 63, 75);
    quarto.setColor(0.1, 0.45, 0.55, 1);
    quarto.putBox(14, 28, 5, 5, 63, 75);

    quarto.writeOFF("../quarto.off");  // salvar no diretório acima
}