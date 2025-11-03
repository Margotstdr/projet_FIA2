#ifndef PROJET_FIA2_PILOTES_H
#define PROJET_FIA2_PILOTES_H

#include "grandprix.h"
#include "ecuries.h"

typedef struct {
    char nom[50];
    char prenom[50];
    char nationalite[50];
    char ecurie[50];
    int points;
    int numero;
    int age;
    int actif;
} Pilote;

void afficherPilote(Pilote *pilotes, int nbPilotes);
void ajouterPilote(Pilote **pilotes, int *nbPilotes, const Ecurie *ecurie, int nbEcuries);
void supprimerPilote(Pilote **pilotes, int *nbPilotes);
void majPoints(Pilote *pilotes, int nbPilotes, GrandPrix *GPS, int nbGP, char nom_circuit[]);

#endif