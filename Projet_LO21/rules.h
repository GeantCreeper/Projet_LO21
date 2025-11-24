/*
 * =============================================================================
 * Projet : Projet_LO21
 * Fichier : rules.h
 * Auteur : Jean Delepine
 * =============================================================================
 */
#ifndef RULES_H
#define RULES_H
#include <stdbool.h>
#include <stdlib.h>

/* Proposition (liste doublement chaînée) */
typedef struct proposition {
    char name;
    bool value;
    struct proposition *next;
    struct proposition *previous;
} Proposition;

typedef struct {
    Proposition *head;
    Proposition *tail;
    int elementcount;
} Premisse;

/* Conclusion */
typedef struct {
    char name;
    bool value;
} Conclusion;

/* Règle : conclusion + prémisse (liste de propositions) */
typedef struct rule {
    Premisse premisse;
    Conclusion conclusion;
    struct rule *next;
    struct rule *previous;
} Regle;

typedef struct {
    Regle *head;
    Regle *tail;
    int elementcount;
} ListofRules;

/* Règles */
ListofRules createEmptyRule(void);
ListofRules emptyRules(ListofRules l);
Regle* newRule(const Premisse pre, const Conclusion c, Regle* next, Regle* previous);
ListofRules insertRuleTail(ListofRules l, Regle r);
ListofRules removeRuleHead(ListofRules l);
ListofRules removeRuleTail(ListofRules l);
Regle* findRuleByConclusion(const ListofRules l, char name);
void displayRules(const ListofRules l); /* affichage sans modifier */

/* Prémisses / propositions */
Premisse createEmptyPremisse(void);
Premisse emptyPremisse(Premisse p);
Proposition* newProposition(char name, bool value, Proposition* next, Proposition* previous);
Premisse addPropTail(Premisse p, Proposition prop);
Premisse removeProposition(Premisse p, char name);
bool isPropositionInPremisse(Premisse p, char name);
bool isPremisseEmpty(Premisse p);
Proposition accessPremisseHead(Premisse p);

/* Conclusion */
Conclusion createConclusion(char name, bool value);
Conclusion accessConclusion(ListofRules rules, char name);

#endif /* RULES_H */