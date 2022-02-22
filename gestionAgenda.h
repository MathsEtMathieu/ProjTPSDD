#ifndef GESTIONAGENDA
#define GESTIONAGENDA

semaine_t * AgendaFromFile (char *);

void libererAgenda (semaine_t **);

date_t ** ListeJoursMotif(semaine_t *, char *);

#endif