#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilotes.h"
#include "ecuries.h"
#include "initialisation.h"


void ajouterPilote(Pilote **pilotes, int *nbPilotes) {

  (*nbPilotes)++;
  Pilote *tmp = realloc(*pilotes, (*nbPilotes) * sizeof(Pilote));
  if (tmp == NULL) {
    printf("Erreur d'allocation mémoire.\n");
    exit(1);
  }
  *pilotes = tmp;

  printf("Nom du pilote : ");
  scanf("%s", (*pilotes)[*nbPilotes - 1].nom);
  printf("Prénom du pilote : ");
  scanf("%s", (*pilotes)[*nbPilotes - 1].prenom);
  printf("Nationalité du pilote : ");
  scanf("%s", (*pilotes)[*nbPilotes - 1].nationalite);
  //void afficher ---------------------------------;
  printf("Nom de l'écurie du pilote : ");
  scanf("%s", (*pilotes)[*nbPilotes - 1].ecurie);
  (*pilotes)[*nbPilotes - 1].points = 0;
  printf("Numéro du pilote : ");
  scanf("%d", &(*pilotes)[*nbPilotes - 1].numero);
  printf("Age du pilote : ");
  scanf("%d", &(*pilotes)[*nbPilotes - 1].age);
  printf("Le pilote est-il actif ? (1 = oui, 0 = non)");
  scanf("%d", &(*pilotes)[*nbPilotes - 1].actif);
}



void afficherPilote(Pilote **pilotes, int *nbPilotes) {

  if ((*nbPilotes) == 0) {
    printf("Aucun pilote enregistré.\n");
    return;
  }

  printf("\n======= LISTE DES PILOTES =======\n");

  for (int i = 0; i < *nbPilotes; i++) {
    printf("%d. %s %s :\n", i+1, (*pilotes)[i].nom, (*pilotes)[i].prenom);
    printf("\t\tNationalité : %s \n", (*pilotes)[i].nationalite);
    printf("\t\tEcurie : %s \n", (*pilotes)[i].ecurie);
    printf("\t\tPoints : %d \n", (*pilotes)[i].points);
    printf("\t\tNumero : %d \n", (*pilotes)[i].numero);
    printf("\t\tAge : %d \n", (*pilotes)[i].age);

    if ((*pilotes)[i].actif == 1) {
      printf("\t\tActif : Oui\n");
    } else {
      printf("\t\tActif : Non\n");
    }
    printf("\n------------------------------\n");
  }

  printf("\n==============================\n\n");

}


void majPoints(Pilote **pilotes, int *nbPilotes, char *nom) {

  int found = 0;

  for (int i = 0; i < *nbPilotes; i++) {
    if (strcmp(nom, (*pilotes)[i].nom) == 0) {
      (*pilotes)[i].points++;
      printf("1 point ajouté à %s %s.\n", (*pilotes)[i].nom, (*pilotes)[i].prenom);
      printf("Total : %d points\n", (*pilotes)[i].points);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Aucun pilote trouvé avec le nom : %s \n", nom);
   }
 }

void supprimerPilote (Pilote **pilotes, int *nbPilotes) {

  int found = 0;
  char nom[50];

  printf("Entrez le nom du pilote à supprimer : ");
  scanf("%s", nom);

  for (int i = 0; i < *nbPilotes; i++) {
    if (strcmp(nom, (*pilotes)[i].nom) == 0) {

      found = 1;

      printf("\n%s %s à été supprimé de la liste.\n", (*pilotes)[i].nom, (*pilotes)[i].prenom);

      for (int j = i+1; j < *nbPilotes - 1; j++) {
        (*pilotes)[j] = (*pilotes)[j - 1];
      }

      (*nbPilotes)--;
      Pilote *tmp = realloc(*pilotes, (*nbPilotes) * sizeof(Pilote));
      if (tmp == NULL && nbPilotes > 0) {
        printf("Erreur d'allocation memoire.\n");
        exit(1);
      }

      *pilotes = tmp;
      break;
    }
  }

  if (!found) {
    printf("\nAucun pilote trouvé avec le nom : %s\n.", nom);
  }
}