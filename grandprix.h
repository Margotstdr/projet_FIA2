#ifndef PROJET_FIA2_GRANDPRIX_H
#define PROJET_FIA2_GRANDPRIX_H
#include "pilotes.h"

typedef struct {
    int jour;
    int mois;
    int annee;
}Date;

typedef struct {
    int heure;
    int minute;
} Heure;

typedef struct {
    char nomPilote[50];
    char prenomPilote[50];
    char nationalite[50];
    int position;
    char tempsRealise[20];
    int pointsObtenus;
} ResultatsCourse;


typedef struct {
    char nomCircuit[50];
    char pays[50];
    int nombreTours;
    Date date;
    Heure horaire;
    ResultatsCourse resultats[20];     // Tableau pour stocker les résultats des pilotes
    int nombreResultats;
    int actif;
} GrandPrix;

void afficherGrandPrix(GrandPrix *GPs, int nbGP);
void ajouterGrandPrix(GrandPrix **GPs, int *nbGP, const Pilote *pilotes, int nbPilotes);
void supprimerGrandPrix(GrandPrix **GPs, int *nbGP);
void ajouterResultatsCourse(GrandPrix *GPs, int nbGP, char nom[], const Pilote *pilotes, int nbPilotes);
void majResultats();



#endif //PROJET_FIA2_GRANDPRIX_H