CC=gcc
CFLAGS = -W -Wall -Wextra -ansi -g
automateTest: main.o fonctionsAffichage.o creationAutomate.o fonctionsMot.o fonctionsOctet.o
	  $(CC) -o automateTest main.o fonctionsAffichage.o creationAutomate.o fonctionsMot.o fonctionsOctet.o $(CFLAGS)

main.o: main.c
	$(CC) -o main.o -c main.c $(CFLAGS)

fonctionsAffichage.o: fonctionsAffichage.c
	$(CC) -o fonctionsAffichage.o -c fonctionsAffichage.c $(CFLAGS)

creationAutomate.o: creationAutomate.c
	$(CC) -o creationAutomate.o -c creationAutomate.c $(CFLAGS)

fonctionsMot.o: fonctionsMot.c
	$(CC) -o fonctionsMot.o -c fonctionsMot.c $(CFLAGS)

fonctionsOctet.o: fonctionsOctet.c
	$(CC) -o fonctionsOctet.o -c fonctionsOctet.c $(CFLAGS)
