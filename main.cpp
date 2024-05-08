#include "sculptor.h"

int main(void){
  Sculptor quarto(100, 100, 100);
  quarto.setColor(0.9, 0.9, 0.9, 0.9); // paredes
  quarto.putBox(0, 99, 0, 99, 0, 99);
  quarto.cutBox(2, 97, 2, 99, 2, 99);
  quarto.setColor(0.99, 0.99, 0.10, 0.9);
  quarto.putBox(2, 12, 42, 58, 48, 64); // estantes
  quarto.cutBox(3, 13, 43, 57, 49, 63);
  quarto.putBox(2, 12, 58, 74, 64, 80);
  quarto.cutBox(3, 13, 59, 73, 65, 79);
  quarto.putBox(2, 12, 26, 42, 32, 48);
  quarto.cutBox(3, 13, 27, 41, 33, 47);
  quarto.setColor(0.39, 0.18, 0.01, 0.9); // janela
  quarto.putBox(34, 68, 34, 68, 0, 3);
  quarto.setColor(0.2, 0.2, 0.9, 0.001);
  quarto.putBox(36, 50, 36, 50, 0, 3);
  quarto.putBox(36, 50, 52, 66, 0, 3);
  quarto.putBox(52, 66, 52, 66, 0, 3);
  quarto.putBox(52, 66, 36, 50, 0, 3);
  quarto.setColor(0.39, 0.18, 0.01, 0.9); // cama
  quarto.putBox(30, 97, 10, 14, 2, 30); 
  quarto.putBox(97, 97, 14, 28, 2, 30);
  quarto.putBox(97, 97, 28, 29, 3, 29);
  quarto.putBox(30, 34, 2, 9, 26, 30); 
  quarto.putBox(30, 34, 2, 9, 3, 7); 
  quarto.putBox(93, 97, 2, 9, 3, 7); 
  quarto.putBox(93, 97, 2, 9, 26, 30); 
  quarto.setColor(0.9, 0.6, 0.1, 0.9);
  quarto.putBox(31, 96, 14, 20, 3, 29);
  quarto.setColor(0.9, 0.9, 0.9, 0.9);
  quarto.putBox(86, 96, 21, 23, 4, 28);
  quarto.setColor(0.39, 0.18, 0.01, 0.9); // escrivaninha
  quarto.putBox(77, 97, 30, 32, 50, 90);
  quarto.putBox(77, 79, 2, 29, 50, 52);
  quarto.putBox(77, 79, 2, 29, 88, 90);
  quarto.putBox(95, 97, 2, 29, 88, 90);
  quarto.putBox(95, 97, 2, 29, 50, 52);
  quarto.setColor(0.20, 0.4, 0.9, 0.9); // cadeira
  quarto.putBox(75, 90, 15, 17, 53, 68);
  quarto.putBox(75, 76, 16, 36, 53, 68);
  quarto.putBox(75, 77, 2, 15, 53, 55);
  quarto.putBox(75, 77, 2, 15, 66, 68);
  quarto.putBox(88, 90, 2, 15, 53, 55);
  quarto.putBox(88, 90, 2, 15, 66, 68);
  quarto.setColor(0.9, 0.9, 0.9, 0.9); // papel
  quarto.putBox(78, 90, 33, 33, 80, 90);
  quarto.setColor(0.1, 0.1, 0.1, 0.9); // lapis
  quarto.putBox(78, 82, 34, 34, 81, 81);
  quarto.setColor(0.1, 0.1, 0.1, 0.9); // notebook
  quarto.putBox(78, 88, 33, 33, 52, 72);
  quarto.putBox(88, 88, 33, 43, 52, 72);
  quarto.setColor(0.9, 0.1, 0.1, 0.9); // livros
  quarto.putBox(3, 11, 43, 57, 50, 50);
  quarto.putBox(3, 11, 43, 57, 50, 50);
  quarto.putBox(3, 11, 59, 73, 67, 67);
  quarto.putBox(3, 11, 59, 73, 78, 78);
  quarto.putBox(3, 11, 27, 41, 34, 34);
  quarto.putBox(3, 11, 27, 41, 40, 40);
  quarto.setColor(0.9, 0.8, 0.3, 0.9);
  quarto.putBox(3, 11, 27, 41, 35, 35);
  quarto.putBox(3, 11, 27, 41, 45, 45);
  quarto.putBox(3, 11, 43, 57, 51, 51);
  quarto.putBox(3, 11, 43, 57, 60, 60);
  quarto.putBox(3, 11, 43, 57, 53, 53);
  quarto.putBox(3, 11, 59, 73, 73, 73);
  quarto.setColor(0.2, 0.12, 0.35, 0.9);
  quarto.putBox(3, 11, 27, 41, 37, 38);
  quarto.putBox(3, 11, 27, 41, 42, 42);
  quarto.putBox(3, 11, 59, 73, 69, 69);
  quarto.putBox(3, 11, 43, 57, 52, 52);
  quarto.putBox(3, 11, 43, 57, 61, 61);
  quarto.putBox(3, 11, 59, 73, 71, 71);
  quarto.setColor(0.1, 0.64, 0.1, 0.9);
  quarto.putBox(3, 11, 27, 37, 39, 39);
  quarto.putBox(3, 11, 27, 41, 42, 42);
  quarto.putBox(3, 11, 59, 70, 65, 65);
  quarto.putBox(3, 11, 43, 57, 56, 56);
  quarto.putBox(3, 11, 43, 57, 62, 62);
  quarto.putBox(3, 11, 59, 73, 72, 72);

  quarto.writeOFF("quarto.off");
}