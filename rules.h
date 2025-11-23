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

typedef struct {
    bool premisse;
    bool conclusion;
} Regle;

Regle createRule();
Regle addProposition();
Regle createConclusion();
bool isPropositionInPremisse();
Regle removeProposition();
bool isPremisseEmpty();
bool PremisseHead();
bool Conclusion();

#endif