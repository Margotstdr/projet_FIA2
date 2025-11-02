//
// Created by Margot Studer on 30/10/2025.
//

#include <stdio.h>
#include "classement.h"
#include "pilotes.h"
#include "ecuries.h"


void classementCourse(GrandPrix *grandPrix) {//on donne le classement général d'UNE seule course
    if (grandPrix == NULL || grandPrix->nombreResultats == 0) {//on vérifie bien que la liste de grand Prix n'est pas vide
        printf("Aucun résultat disponible pour ce Grand Prix.\n");
        return;
    }

    printf("\n=== Classement du Grand Prix de %s (%s) ===\n",
           grandPrix->nomCircuit, grandPrix->pays);
    printf("Nombre de tours : %d\n\n", grandPrix->nombreTours);

    //Tri du tableau resultats par position croissante (1er, 2e, 3e, etc.)
    for (int i = 0; i < grandPrix->nombreResultats - 1; i++) { //on utilise les flèches puisque c'est une structure qui pointe vers une autre structure
        for (int j = i + 1; j < grandPrix->nombreResultats; j++) {
            if (grandPrix->resultats[i].position > grandPrix->resultats[j].position) {//tri à bulle
                ResultatsCourse temp = grandPrix->resultats[i];
                grandPrix->resultats[i] = grandPrix->resultats[j];
                grandPrix->resultats[j] = temp;
            }//donc par exemple si [i] est à la pos 5 et [j] à la pos 4
        }//on va switch la place de i et j
    }

    //on affiche le classement
    for (int i = 0; i < grandPrix->nombreResultats; i++) {
        ResultatsCourse resCourse = grandPrix->resultats[i];
        printf("%2d. %-15s %-15s | %-12s | Temps : %-10s | Points : %2d\n",
               resCourse.position, resCourse.prenomPilote, resCourse.nomPilote, resCourse.nationalite,
               resCourse.tempsRealise, resCourse.pointsObtenus);
    }
}

void classementPiloteGP (GrandPrix *GPs, int nbGrandPrix, Pilote *pilotes, int nbPilotes) {
    if (GPs == NULL || pilotes == NULL) return;

    // on remet tous les points à 0 avant le calcul des points du pilote
    for (int i = 0; i < nbPilotes; i++) {
        pilotes[i].points = 0;
    }

    //on parcours tous les GrandPrix
    for (int i = 0; i < nbGrandPrix; i++) {
        GrandPrix gp = GPs[i];

        if (!gp.actif) continue; //tout ce qui est différent de 1, donc inactif, est ignoré

        //parcours de tous les résultats du GrandPrix
        for (int j = 0; j < gp.nombreResultats; j++) {
            ResultatsCourse resCourse = gp.resultats[j];

            //on va chercher le pilote correspondant dans le tableau Pilote
            for (int k = 0; k < nbPilotes; k++) {
                if (strcmp(pilotes[k].nom, r.nomPilote) == 0 &&//avec strcmp, on vérifie que ce soit bien le même pilote à qui on augmente lespoints
                    strcmp(pilotes[k].prenom, r.prenomPilote) == 0){// avec strcmp si c'est égal à 0, alors c'est tout bon ! 
                    pilotes[k].points += r.pointsObtenus;
                    break;
                }
            }
        }
    }
}
















//*
//*classement course :
//switch (GPs[i].resultats->position) {
  //  case 1:
  //GPs[i].resultats->pointsObtenus += 25;
    //    pilotes
      //case 2:
        //GPs[i].resultats->pointsObtenus += 10;//
