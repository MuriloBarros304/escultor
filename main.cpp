#include "sculptor.h"

int main(void){
  Sculptor quarto(100, 100, 100);
  quarto.setColor(0.9, 0.9, 0.9, 0.9);
  quarto.putBox(0, 99, 0, 99, 0, 99);
  quarto.cutBox(2, 97, 2, 99, 2, 99);
  quarto.setColor(0.99, 0.99, 0.10, 0.9);
  quarto.putBox(2, 12, 42, 58, 48, 64);
  quarto.cutBox(3, 13, 43, 57, 49, 63);
  quarto.putBox(2, 12, 58, 74, 64, 80);
  quarto.cutBox(3, 13, 59, 73, 65, 79);
  quarto.putBox(2, 12, 26, 42, 32, 48);
  quarto.cutBox(3, 13, 27, 41, 33, 47);
  quarto.setColor(0.39, 0.18, 0.01, 0.9);
  quarto.putBox(34, 68, 34, 68, 0, 3);
  quarto.cutBox(36, 50, 36, 50, 0, 3);
  quarto.cutBox(36, 50, 52, 66, 0, 3);
  quarto.cutBox(52, 66, 52, 66, 0, 3);
  quarto.cutBox(52, 66, 36, 50, 0, 3);

  quarto.writeOFF("quarto.off");
}