/*
creationAutomate.h

contient les fonctions pour les divers affichagesla lecture et la définition de l'automate
*/
int creationAlphabet(char tmp[], automate_t * automate);
enum boolean contains(char lettreaTester, char mot[]);
enum boolean transfoMotToOctet(char mot[], automate_t * automate );
void transformationTransitionCharToOctet(transition_t transition, automate_t * automate);
void definitionTransition(char *tmp, int cpt, automate_t * automate );
void definitionAutomate(char *argv[], automate_t * automate, int * taille);
int testLettre(transition_t transition, octet o);
enum boolean testMot(automate_t * automate);
