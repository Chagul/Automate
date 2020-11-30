README DU PROJET C DE AURELIEN PLANCKE GROUPE B
Voici les piste d'améliorations auquel j'ai pensées mais que je n'ai pas pu appliquer manque de temps :
-Remodeller les structures pour remplacer les tableaux par des pointeurs, ça m'aurait permis d'avoir des tailles de structures modulables à l'allocation, en lisant la taille de l'alphabet, le nombre de transition. Le defaut actuel est le fait que ces tableaux doivent être déclarer à taille fixe dès le debut.
-Ajouter le mot vide à la lecture des mots, actuellement la structure de controle des paramètres ne le permet pas
-Permettre la lecture de differents mots donnés en paramètres, en faisant une structure ListeMot qui stockerait tout les differents mots lu et testerait chacun d'eux
-Pour permettre la lecture des automates non déterministe j'avais dans l'idée de parcourir chaque état, sauvegarder l'état dans lequel une lettre est accepté, et si la suite des transitions ne permet l'acceptation du mot, on revient sur cet état sauvegarder et on lit la suite de la transition jusqu'à une eventuelle réussite de l'acceptation du mot 
