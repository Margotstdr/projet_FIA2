#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grandprix.h"

void afficherGrandPrix(GrandPrix **grandprix, int *nbGP) {

    if ((*nbGP) == 0) {
        printf("Aucun Grand Prix enregistré.\n");
        return;
    }

    printf("\n====== LISTE DES GRANDS PRIX ======\n");

    for (int i = 0; i < (*nbGP); i++) {
        printf("Grand Prix %d : \n", i + 1);
        printf("\tNom du circuit : %s\n", (*grandprix)[i].nomCircuit);
        printf("\tPays : %s\n", (*grandprix)[i].pays);
        printf("\tNombre de tours : %d\n", (*grandprix)[i].nombreTours);
        printf("\tDate : le %d/%d/%d à %d:%d\n",
            (*grandprix)[i].date.jour, (*grandprix)[i].date.mois, (*grandprix)[i].date.annee,
            (*grandprix)[i].horaire.heure, (*grandprix)[i].horaire.minute);
        printf("\tNombre de coureurs : %d\n", (*grandprix)[i].nombreResultats);

        if ((*grandprix)[i].actif == 1) {
            printf("\tActif : Oui\n");
        } else {
            printf("\tActif : Non\n");
        }

        printf("\n------------------------------\n");
    }

    printf("\n==============================\n\n");

}

