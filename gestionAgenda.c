#include "structures.h"
#include "gestionAction.h"
#include "gestionSemaine.h"
#include "gestionAgenda.h"
#include <stdio.h>
#include <stdlib.h>

semaine_t * AgendaFromFile(char * nom) {
    char ligne[11];
    FILE * file = fopen(nom, "r");
    semaine_t * agenda = NULL;

    if (file) {
        while (feof(file)==0) {
            fgets(ligne, 19, file);
            printf("%s\n", ligne);
            gestionAction(SemaineFromLigne(ligne, &agenda), ligne);
        }
    }
    return(agenda);
}

void libererAgenda(semaine_t * agenda) {
    semaine_t * cour = NULL;
    semaine_t * temp = NULL;

    if (agenda) {
        cour = agenda;

        while (cour) {
            temp = cour;
            cour = cour->suiv;
            libererListeActions(temp->actions);
            free(temp);
        }
        agenda = NULL;
    }
}

date_t ** ListeJoursMotif(semaine_t * agenda, char * motif) {
    date_t ** liste = malloc(2 * sizeof(date_t *));
    date_t * debut = malloc(100 * sizeof(date_t));
    date_t * fin = debut;

    int i, annee, semaine;
    int * listeJours;
    semaine_t * cour = agenda;

    while ((cour) && (fin-debut < 100)) {
        annee = (cour->annee_semaine)/100;
        semaine = (cour->annee_semaine)%100;

        listeJours = listeMotif(cour, motif);

        for(i=0; (fin-debut < 100) && (listeJours[i] != 0); i++) {
            fin->jour = listeJours[i];
            fin->semaine = semaine;
            fin->annee = annee;
            fin += 1; 
        }

        free(listeJours);
        listeJours = NULL;
        cour = cour->suiv;
    }

    if (fin-debut == 100) printf("Liste de jours pleine.\n");

    liste[0] = debut;
    liste[1] = fin;
    return(liste);
}