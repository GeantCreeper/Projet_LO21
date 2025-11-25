/*
 * =============================================================================
 * Projet : Projet_LO21
 * Fichier : knowledge.h
 * Auteur : Jean Delepine
 * =============================================================================
 */
#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include "header.h"

typedef struct {
    Proposition *head;
    Proposition *tail;
    int elementcount;
} BF;

BF createEmptyBF(void);
BF emptyBF(BF l);
BF insertFactTail(BF l, Proposition p);
BF removeFactHead(BF l);
BF removeFactTail(BF l);
Regle accessBFHead(BF l);
void displayFacts(BF l); /* affichage sans modifier */

deduceFacts(BF facts, BC knowledgeBase, BF deducted);

#endif
