#ifndef GESTIONACTION
#define GESTIONACTION



void libererListeActions(listeAction_t *);

void gestionAction(semaine_t *, char *);

int * listeMotif(semaine_t *, char *);

void afficherActions(listeAction_t *);

#endif