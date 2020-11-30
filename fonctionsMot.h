/*fonctionsMot.h
Contient toutes les fonctions déstinées à manipuler et creer le mot
*/
enum boolean transfoMotToOctet(char mot[], automate_t * automate );
enum boolean testMot(automate_t * automate);
int testLettre(transition_t transition, octet o);
enum boolean contains(char lettreaTester, char mot[]);
