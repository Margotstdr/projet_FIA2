#include <stdio.h>
#include "pilotes.h"
#include "ecuries.h"
#include "grandprix.h"
#include "classement.h"
#include "initialisation.h"

int main() {

    Pilote *pilotes = NULL;
    int nbPilotes = 0;
    GrandPrix *grandprix = NULL;
    int nbGP = 0;

    initialiserPilotes(&pilotes, &nbPilotes);
    initialiserGrandPrix(&grandprix, &nbGP);
    //afficherPilote(&pilotes, &nbPilotes);
    //supprimerPilote(&pilotes, &nbPilotes);
    //afficherPilote(&pilotes, &nbPilotes);
    afficherGrandPrix(&grandprix, &nbGP);

    return 0;
}