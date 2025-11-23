/*
 * =============================================================================
 * Projet : Projet_LO21
 * Fichier : knowledge.h
 * Auteur : Jean Delepine
 * =============================================================================
 */
#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H
#include <stdbool.h>

typedef struct {
} BC;

BC createEmptyKnowledge();
BC addRuleToKnowledge();
bool RuleHeadInKnowledge();

#endif