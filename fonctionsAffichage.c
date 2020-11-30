/*Ce code source contient tout les fonctions déstinées à afficher les differents composants de l'automate*/
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctionsAffichage.h"
#include "creationAutomate.h"

void affichageAlphabet(automate_t *automate, int taille){
  /**affiche l'alphabet
   **/
  int i = 0;
  for(; i < taille; i++){
    printf("%c sera codé à la %d position d'un octet \n",automate->alphabet.alphabetC[i],automate->alphabet.alphabetI[i]);
  }
}

void affichageEtatInitial(automate_t *automate){
  /**affiche l'etatInitial
   **/
  printf("L'état Inital est %d \n",automate->etatInitial);
}

void affichageEtatAcceptant(automate_t *automate){
  /** affiche le ou les etat final/finaux
   **/
  int i = 0;
  printf("L'état final/Les états finaux :"); 
  while(automate->etatAcceptant[i] != '\0'){
    printf("%c",automate->etatAcceptant[i]);
    i++;
  }
  printf("\n");
}

void affichageTransition(automate_t *automate){
  /** permet d'afficher les différentes transitions
   **/
  int i = 0;
  int j = 0;
  while(automate->transition[i].etatTransition != -1){
    printf("Transition depuis l'état %d : ", automate->transition[i].etatTransition);
    while(automate->transition[i].transition[j] != '\0'){
      printf("%c",automate->transition[i].transition[j]);
      j++;
    }
    j = 0;
    i++;
    printf("\n");
  }
}

void affichageGeneral(automate_t * automate, int taille){
  /*permet de faire tout les affichages d'un coup*/
  affichageAlphabet(automate, taille);
  affichageEtatInitial(automate);
  affichageEtatAcceptant(automate);
  affichageTransition(automate);
}
