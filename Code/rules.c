#include "header.h"

Rule createRule() {
    Rule r;
    r.premisse = malloc(sizeof(Premisse));
    *r.premisse = createPremisse();
    strcpy(r.conclusion, "");
    return r;
}

void addPropositionToPremisse(Rule *r, char *proposition) {
    addProposition(r -> premisse, proposition);
}

void createConclusion(Rule *r, char *proposition) {
    strcpy(r -> conclusion, proposition);
}

char *accessConclusion(Rule r) {
    return r.conclusion;
}

void deleteRule(Rule *r) {
    if (r -> premisse != NULL) {
        deletePremisse(r -> premisse);
        free(r -> premisse);
        r -> premisse = NULL;
    }
    strcpy(r -> conclusion, "");
}
