
#ifndef PROJET_FIA2_ECURIES_H
#define PROJET_FIA2_ECURIES_H

#include "pilotes.h"

typedef struct {
    char nom[50];
    char pays[50];
    int points;
    int anneeCreation;
    char directeur[50];
    int actif;
    Pilote p1;
    Pilote p2;
} Ecurie;

#endif //PROJET_FIA2_ECURIES_H