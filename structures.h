#ifndef STRUCTURES
#define STRUCTURES

typedef struct action {
    int jour_heure;
    char nom_action[10];
    struct action * suiv;
} action_t;

typedef struct {
    action_t * debut;
} listeAction_t;

typedef struct semaine {
    int annee_semaine;
    listeAction_t * actions;
    struct semaine * suiv;
} semaine_t;

typedef struct {
    int jour;
    int semaine;
    int annee;
} date_t;

#endif