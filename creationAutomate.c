/*Ce code source réuni tout les fonctions déstinées à lire notre automate et à le définir */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "creationAutomate.h"
#include "fonctionsOctet.h"

#define MAX_LENGTH 40


int creationAlphabet(char tmp[], automate_t * automate){
  /**
     Création de l'alphabet
  **/
  int i = 0;
  while(tmp[i] != '\n'){
    automate->alphabet.alphabetC[i] = tmp[i];
    automate->alphabet.alphabetI[i] = i;
    i++;
  }
  automate->alphabet.alphabetC[i] = '\0';
  automate->alphabet.alphabetI[i] = -1;
  return i;
}

void transformationTransitionCharToOctet(transition_t transition, automate_t * automate){
  /*Les transitions seront ici transformé en Octet afin de pouvoir controler les différentes lettre du mot entré en paramètre*/
  int cptChaine = 0;
  int cptEtat = 0;
  if(transition.etatTransition != -1){
    printf("==========%d=========", transition.etatTransition);
    printf("\n Depuis l'état %d  \n\n", transition.etatTransition );
    
    while(transition.transition[cptChaine] != '\0'){
      if(transition.transition[cptChaine] == ';' && cptChaine == 0){
	printf("\nVers l'état %d :", cptEtat);
	set_octet_0(transition.transitionO[cptEtat]);
	affichage_octet(transition.transitionO[cptEtat]);
	cptChaine++;
	cptEtat++;
      }else if((transition.transition[cptChaine-1] == ';') && (transition.transition[cptChaine] == ';')){
	printf("\nVers l'état %d :", cptEtat);
	cptEtat++;
	set_octet_0(transition.transitionO[cptEtat]);
	affichage_octet(transition.transitionO[cptEtat]);
	cptChaine++;
      }else if(transition.transition[cptChaine] == ';' && transition.transition[cptChaine - 1] != ';' ){
	cptChaine++;
      }else{
	printf("\nVers l'état %d :", cptEtat);
	while(transition.transition[cptChaine] != ';' && transition.transition[cptChaine] != '\0'){
	  automate->transition[transition.etatTransition].transitionO[cptEtat] = set_bit((int)transition.transition[cptChaine] - 97, automate->transition[transition.etatTransition].transitionO[cptEtat]);
	  cptChaine++;
	}
	affichage_octet(automate->transition[transition.etatTransition].transitionO[cptEtat]);
	cptEtat++;
      }
    }  
  }
  printf("\n");
}
void definitionTransition(char *tmp, int cpt,automate_t * automate){
  /*Definition des transitions avec leur numéro qui sont directement attribué à notre automate */
  int i = 0;
  automate->transition[cpt].etatTransition = cpt;
  while(tmp[i] != '\0'){
    automate->transition[cpt].transition[i] = tmp[i];
    i++;
  }
  automate->transition[cpt].transition[i] = '\0';
  transformationTransitionCharToOctet(automate->transition[cpt], automate);
}
 
void definitionAutomate(char *argv[], automate_t * automate, int * taille){
  /**Creer les différentes partie de l'automate à partir du fichier lu
   **/
  FILE *inputfile = fopen(argv[1], "r");
  char *tmp = (char*) malloc(MAX_LENGTH);
  int cpt = 0;
  int cptTransition = 0;
  printf("Vous avez ouvert le fichier %s \n",argv[1]);
  printf("Votre mot à tester est %s \n", argv[2]);
  while( ! feof(inputfile)){
    fgets(tmp,MAX_LENGTH, inputfile);
    if(cpt == 0){
      * taille = creationAlphabet(tmp, automate);
    }else if(cpt == 1){
      automate->etatInitial = (int)tmp[0] - '0';
    }else if(cpt == 2){
      int i = 0;
      while(tmp[i] != '\n'){
	automate->etatAcceptant[i] = tmp[i];
	i++;
      }
      automate->etatAcceptant[i] = '\0';
    }else if(cpt < 8){
      definitionTransition(tmp, cptTransition, automate);
      cptTransition++;
    }
    cpt++;
  }
  automate->transition[cptTransition].etatTransition = -1; /* on fixe un état "poubelle" afin de faire un controle et ne pas depasser de la mémoire*/
  free(tmp);
  fclose(inputfile);
}

  
