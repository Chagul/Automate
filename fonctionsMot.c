/*Ce code source est destiné à preparer le mot lu en parametre et à le manipuler*/
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctionsMot.h"
#include "fonctionsOctet.h"

mot_t leMot;

enum boolean transfoMotToOctet(char mot[], automate_t * automate ){
  /*On transforme le mot lu en tableau d'octet afin de pouvoir tester chaque lettre avec les octet des transitions*/
  int i = 0;
  while(mot[i] != '\0' ){
    set_octet_0(leMot.mot[i]);
    leMot.mot[i] = set_bit((int)mot[i] - 97, leMot.mot[i]);
    leMot.motChar[i] = mot[i];
    if(! contains(mot[i], automate->alphabet.alphabetC) && mot[i] != '\0') {
      printf("LE MOT %s EST INVALIDE : ", mot);
      return FAUX;
    }
    ++i;
  }
  leMot.motChar[i] = '\0';
  return VRAI;
}

enum boolean testMot(automate_t * automate){
  /*On vérifie lettre à lettre si le mot est accepté par l'automate
    return VRAI si le mot est accepté, FAUX sinon*/
  int i = 0;
  int tmp = 0;
  int j = 0;
  for(;leMot.motChar[j] != '\0'; j++)
    if(!contains(leMot.motChar[j], automate->alphabet.alphabetC))
      return FAUX;
  while(leMot.motChar[i] != '\0' && leMot.motChar[i] != '\n'){
    if(tmp == -1)
      return FAUX;
    if(i == 0){
      printf("Demarrage état %d -(%c)>", automate->transition[automate->etatInitial].etatTransition,leMot.motChar[i]);
      tmp = testLettre(automate->transition[automate->etatInitial], leMot.mot[i]);
    }
    else if(i != 0 ){
      printf("Entrée dans l'état %d -(%c)>", automate->transition[tmp].etatTransition,leMot.motChar[i]);
      tmp = testLettre(automate->transition[tmp], leMot.mot[i]);
    }
    i++;
  }
  if(leMot.motChar[i] == '\0' && tmp != -1){
    printf("Arrivée dans l'état %d -(%c)>", automate->transition[tmp].etatTransition,leMot.motChar[i]);
    if( contains((char)(tmp + 48), automate->etatAcceptant))
      return VRAI;
  }
  return FAUX;
}
int testLettre(transition_t transition, octet o){
  /*On teste l'octet representant une lettre avec chaque octet d'une transition, si le resultat est différent de 0, il y a une lettre en commun
    renvoie le numéro de transition suivante si existe, sinon -1*/
  int i = 0;
  while(transition.transition[i] != '\0'){
    if((transition.transitionO[i] & o) != 0x00)
      return i;
    i++;
  }
  return -1;
}

enum boolean contains(char lettreaTester, char mot[]){
  /*Verifie si une lettre est contenue dans un mot
    renvoie VRAI si la lettre est dans le mot, FAUX sinon*/
  int i = 0;
  if(lettreaTester == mot[i])
    return VRAI;
  while(lettreaTester != mot[i] && mot[i] != '\0')
    i++;
  if(lettreaTester == mot[i] && mot[i] != '\0'){
    return VRAI;
  }
  return FAUX;
}

