#include "structures.h"
#include "gestionAction.h"
#include "gestionSemaine.h"
#include "gestionAgenda.h"
#include <stdio.h>

int main(int argc, char * argv[]) {
    semaine_t * agenda = NULL;

    if (argc>1) {
        agenda = AgendaFromFile(argv[1]);
    }
    else printf("Pas de nom de fichier donné\n");


    if (agenda == NULL) {
        printf("Pas OK Agenda\n");
    }
    else printf("OK %d\n", agenda->annee_semaine);

    afficherSemaine(agenda);

    libererAgenda(agenda);

    return(0);
}