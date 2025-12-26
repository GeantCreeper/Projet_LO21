#include "header.h"

Rule createRule() {//alloue memoire pour une regle et initialise ses champs
    Rule r;
    r.premisse = malloc(sizeof(Premisse));
    *r.premisse = createPremisse();
    strcpy(r.conclusion, "");
    return r;
}

void addPropositionToPremisse(Rule *r, char *proposition) {//ajoute une proposition a la premisse d'une regle
    addProposition(r -> premisse, proposition);
}

void createConclusion(Rule *r, char *proposition) {//cree la conclusion d'une regle
    strcpy(r -> conclusion, proposition);
}

char *accessConclusion(Rule r) {//renvoie la conclusion d'une regle
    return r.conclusion;
}

void deleteRule(Rule *r) {//libere la memoire allouee pour une regle et ses champs
    if (r -> premisse != NULL) {
        deletePremisse(r -> premisse);
        free(r -> premisse);
        r -> premisse = NULL;
    }
    strcpy(r -> conclusion, "");
}
