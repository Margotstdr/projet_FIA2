#include <stdio.h>
#include "pilotes.h"
#include "ecuries.h"
#include "grandprix.h"
#include "classement.h"
#include "initialisation.h"

int main() {

    Pilote *pilotes = NULL;
    int nbPilotes = 0;
    GrandPrix *GPs = NULL;
    int nbGP = 0;

    initialiserPilotes(&pilotes, &nbPilotes);
    initialiserGrandPrix(&GPs, &nbGP);
    //afficherPilote(&pilotes, &nbPilotes);
    //supprimerPilote(&pilotes, &nbPilotes);
    //afficherPilote(&pilotes, &nbPilotes);
    afficherGrandPrix(&GPs, &nbGP);
    ajouterGrandPrix(&GPs, &nbGP);

    return 0;
}