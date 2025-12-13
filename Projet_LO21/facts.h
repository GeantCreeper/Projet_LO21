/*
 * =============================================================================
 * Projet : Projet_LO21
 * Fichier : knowledge.h
 * Auteur : Jean Delepine
 * =============================================================================
 */
#ifndef FACTS_H
#define FACTS_H

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
Proposition accessBFHead(BF l);
void displayFacts(BF l); /* affichage sans modifier */

BF deduceFacts(BF fact_base, BC knowledge_base);

#endif
