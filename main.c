#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "creationAutomate.h"
#include "fonctionsAffichage.h"
#include "fonctionsOctet.h"

#define NOMBRE_ARG (2) /*nombre d'arguments max lu en paramètre*/
automate_t automate;
automate_t * ptrAutomate = &automate;  /*on a besoin d'une variable globale pour pouvoir acceder à l'automate partout*/

int main(int argc, char * argv[]){
  int taille = 0;
  int * ptrTaille = &taille;
  argc--; /*on enlève le comptage de l'executable*/
  if(argc != NOMBRE_ARG ){
    printf("Vous devez entrez une commande sous cette forme : \".projet.c chemindufichierdécrivantl'automate motATesterAvecCetteAutomate\" ");
    return 1;
    }else{
    definitionAutomate(argv, ptrAutomate, ptrTaille);
    affichageGeneral(ptrAutomate, taille);
    transfoMotToOctet(argv[2], ptrAutomate); /* on transforme le mot lu en paramètres en octet*/
    if(testMot(ptrAutomate)){
      printf("LE MOT EST ACCEPTE");
    }else{
      printf("LE MOT N'EST PAS ACCEPTE :(");
      return 1;
    }
  }
return 0;
}
