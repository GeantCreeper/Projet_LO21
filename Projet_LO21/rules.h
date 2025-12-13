/*
 * =============================================================================
 * Projet : Projet_LO21
 * Fichier : rules.h
 * Auteur : Jean Delepine
 * =============================================================================
 */
#ifndef RULES_H
#define RULES_H

/* Proposition (liste doublement chaînée) */
typedef struct proposition {
    char name;
    struct proposition *next;
    struct proposition *previous;
} Proposition;

typedef struct {
    Proposition *head;
    Proposition *tail;
    int elementcount;
} Premisse;

/* Règle : conclusion + prémisse (liste de propositions) */
typedef struct rule {
    Premisse premisse;
    Proposition conclusion;
    struct rule *next;
    struct rule *previous;
} Regle;

typedef struct {
    Regle *head;
    Regle *tail;
    int elementcount;
} BC;

/* Propositions */
Proposition* newProposition(char name, Proposition* next, Proposition* previous);
bool isPropositionInPremisse(Premisse p, char name);
Proposition createConclusion(char name);
Proposition accessConclusion(BC rules, char name);

/* Prémisses */
Premisse createEmptyPremisse(void);
Premisse emptyPremisse(Premisse p);
Premisse addPropTail(Premisse p, Proposition prop);
Premisse removeProposition(Premisse p, char name);
bool isPremisseEmpty(Premisse p);
Proposition accessPremisseHead(Premisse p);



/* Règles */
Regle* newRule(Premisse pre, Proposition c, Regle* next, Regle* previous);
Regle createEmptyRule(void);

/* Base de connaissances */
BC createEmptyBC(void);
BC emptyBC(BC l);
BC insertRuleTail(BC l, Regle r);
BC removeRuleHead(BC l);
BC removeRuleTail(BC l);
Regle accessBCHead(BC l);
void displayRules(BC l);

#endif /* RULES_H */