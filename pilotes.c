#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilotes.h"
#include "ecuries.h"
#include "initialisation.h"

Pilote *pilotes = NULL;
int nbPilotes = 0;

void ajouterPilote() {

  nbPilotes++;
  Pilote *tmp = realloc(pilotes, nbPilotes * sizeof(Pilote));
  if (tmp == NULL) {
    printf("Erreur d'allocation mémoire.\n");
    exit(1);
  }
  pilotes = tmp;

  printf("Nom du pilote : ");
  scanf("%s", pilotes[nbPilotes - 1].nom);
  printf("Prénom du pilote : ");
  scanf("%s", pilotes[nbPilotes - 1].prenom);
  printf("Nationalité du pilote : ");
  scanf("%s", pilotes[nbPilotes - 1].nationalite);
  //void afficher ---------------------------------;
  printf("Nom de l'écurie du pilote : ");
  scanf("%s", pilotes[nbPilotes - 1].ecurie);
  pilotes[nbPilotes - 1].points = 0;
  printf("Numéro du pilote : ");
  scanf("%d", &pilotes[nbPilotes - 1].numero);
  printf("Age du pilote : ");
  scanf("%d", &pilotes[nbPilotes - 1].age);
  printf("Le pilote est-il actif ? (1 = oui, 0 = non)\n");
  scanf("%d", &pilotes[nbPilotes - 1].actif);
}



void afficherPilote() {

  if (nbPilotes == 0) {
    printf("Aucun pilote enregistré.\n");
    return;
  }

  printf("\n===== LISTE DES PILOTES =====\n");

  for (int i = 0; i < nbPilotes; i++) {
    printf("Pilote : %d \n", i + 1);
    printf("Nom : %s \n", pilotes[i].nom);
    printf("Prénom : %s \n", pilotes[i].prenom);
    printf("Nationalité : %s \n", pilotes[i].nationalite);
    printf("Ecurie : %s \n", pilotes[i].ecurie);
    printf("Points : %d \n", pilotes[i].points);
    printf("Numero : %d \n", pilotes[i].numero);
    printf("Age : %d \n", pilotes[i].age);
    if (pilotes[i].actif == 1) {
      printf("Actif : Oui\n");
    } else {
      printf("Actif : Non\n");
    }
  }

  printf("\n==============================\n");

}


void majPoints(char *nom) {

  int found = 0;

  for (int i = 0; i < nbPilotes; i++) {
    if (strcmp(nom, pilotes[i].nom) == 0) {
      pilotes[i].points++;
      printf("1 point ajouté à %s %s.\n", pilotes[i].nom, pilotes[i].prenom);
      printf("Total : %d points\n", pilotes[i].points);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Aucun pilote trouvé avec le nom : %s \n", nom);
   }
 }