#ifndef GESTIONSEMAINE
#define GESTIONSEMAINE

semaine_t * SemaineFromLigne (char *, semaine_t **);

semaine_t * creerSemaine (int, semaine_t *, semaine_t *);

semaine_t ** chercherSemaine (int, semaine_t *);

void afficherSemaine(semaine_t *);

#endif