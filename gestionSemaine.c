#include "structures.h"
#include "gestionAction.h"
#include "gestionSemaine.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



semaine_t * SemaineFromLigne(char * ligne, semaine_t ** p_agenda) {
    int a_s;
    char aux[6];
    strncpy(aux, ligne, 6);
    sscanf(aux, "%d", &a_s); //a_s contient le nombre composé des 6 premiers chiffres du string "ligne"

    semaine_t ** sem = chercherSemaine(a_s, *p_agenda);
    semaine_t * res = NULL;
    
    if (*p_agenda) {
        if ((*(sem+1))==NULL || (*(sem+1))->annee_semaine != a_s) {
            res = creerSemaine(a_s, *sem, *(sem+1));
            if (!(*sem)) {
                *p_agenda = res;
            }
        }

        else {
            res = *(sem+1);
        }
    }
    else {
        *p_agenda = creerSemaine(a_s, NULL, NULL);
    }
    return(res);
}


semaine_t ** chercherSemaine(int a_s, semaine_t * agenda) {
    semaine_t ** res = malloc(2 * sizeof(semaine_t *));
    *res = *(res+1) = NULL;

    if (agenda) {
        *res = NULL;
        *(res+1) = &(*agenda);

        while ((*(res+1)) && (*(res+1))->annee_semaine<a_s) {
            *res = *(res+1);
            *(res+1) = (*(res+1))->suiv;
        }
    }
    return (res);
}


semaine_t * creerSemaine(int a_s, semaine_t * prec, semaine_t * suiv) {
    semaine_t * sem = malloc(sizeof(semaine_t));
    if (sem) {
        sem->actions = malloc(sizeof(listeAction_t));
        sem->annee_semaine = a_s;
        sem->suiv = suiv;
        if (prec) prec->suiv = sem;     //On fait ce test car on prendra prec = NULL pour créer la semaine en tête de liste
    }
    else {
        exit(1);
    }
    return(sem);
}



void afficherSemaine(semaine_t * agenda) {
    semaine_t * cour = agenda;
    int a_s;

    while (cour) {
        a_s = cour->annee_semaine;
        printf("Annee %d, semaine %d :\n", a_s/100, a_s%100);
        cour = cour->suiv;
    }
}