#include "sculptor.h"

int main(void){
  Sculptor teste(100, 100, 100);
  teste.setColor(1, 0, 0.0, 1);
  teste.putVoxel(1, 1, 1);
  teste.putEllipsoid(25, 50, 50, 10, 20, 25);
  //teste.setColor(0,1,0,0.9);
  //teste.putSphere(50,50,50,40);
  teste.writeOFF("teste.off");
}