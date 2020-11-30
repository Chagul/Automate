typedef unsigned char octet;

typedef struct{
  int alphabetI[9];
  char alphabetC[9];
} alphabet_t;

typedef struct{
  char transition[50];
  int etatTransition;
  octet transitionO[5];
} transition_t;

typedef struct{
  alphabet_t alphabet;
  int etatInitial;
  char etatAcceptant[6];
  transition_t transition[5];
} automate_t;

typedef struct{
  char motChar[9];
  octet mot[9];
}mot_t;

enum boolean {FAUX,VRAI};
