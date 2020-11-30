/*Ce code source rassemble les fonctions destinées à manipuler des octets*/
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void affichage_octet(octet o){
  printf("0x%x",o);
  
}octet set_octet_0(octet o){
  /*met un octet à 0x00 et le return*/
  return o &= 0x00;
}

octet set_bit(int pos, octet o){
  /*permet de mettre un bit à 1 à la position (pos) donnée*/
  return o |= (1 << pos);
}
