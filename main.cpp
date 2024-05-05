#include "sculptor.h"

int main(void){
  Sculptor teste(20, 20, 20);
  teste.setColor(0.9, 0.5, 0.1, 0.9);
  teste.putVoxel(0,0,0);
  teste.setColor(0.9, 0.1, 0.1, 0.9);
  teste.putBox(1,5,1,6,1,8);
  teste.putSphere(10, 10, 10, 3);
  //teste.putVoxel(1, 1, 1);
  //teste.putVoxel(5, 5, 5);
  //teste.putEllipsoid(25, 50, 50, 10, 20, 25);
  //teste.setColor(0,1,0,0.9);
  //teste.putSphere(50,50,50,40);
  teste.writeOFF("teste.off");
}