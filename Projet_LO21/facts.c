/*
 * =============================================================================
 * Projet : Projet_LO21
 * Fichier : knowledge.c
 * Auteur : Jean Delepine
 * =============================================================================
 */

#include "header.h"

BF deduceFacts(BF fact_base, BC knowledge_base) { 
    BF deducted = createEmptyBF();
    for (int i = 0; i < fact_base.elementcount; i++) {
        for (int j = 0; j < knowledge_base.elementcount; j++) {
            if (fact_base.head -> name == knowledge_base.head -> premisse.head -> name) {
                removeFactHead(fact_base);
                knowledge_base.head -> premisse = removeProposition(knowledge_base.head -> premisse, fact_base.head -> name);
                if (isPremisseEmpty(knowledge_base.head -> premisse)) {
                    insertFactTail(fact_base, knowledge_base.head -> conclusion);
                    insertFactTail(deducted, knowledge_base.head -> conclusion);
                }
            }
        }
    }
    return deducted;
}

BF createEmptyBF(void) {
    BF l;
    l.head = NULL;
    l.tail = NULL;
    l.elementcount = 0;
    return l;
}

BF emptyBF(BF l) {
    if (l.head == NULL) {
        return l;
    }
    else {
        Proposition *p = l.head;
        Proposition *tmp = NULL;
        while (p != NULL) {
            tmp = p -> next;
            free(p);
            p = tmp;
        }
        l.head = NULL;
        l.tail = NULL;
        l.elementcount = 0;
    }
    return l;
}

BF insertFactTail(BF l, Proposition p) {
    Proposition *newel = newProposition(p.name, p.value, NULL, NULL);
    if (l.head == NULL) {
        l.head = l.tail = newel;
        l.elementcount++;
    } else {
        l.tail -> next = newel;
        newel -> previous = l.tail;
        l.tail = newel;
        l.elementcount++;
    }
    return l;
}

BF removeFactHead(BF l) {
    if (l.head != NULL) {
        Proposition *p = l.head;
        l.head = l.head -> next;
        if (l.head != NULL) {
            l.head -> previous = NULL;
        } else {
            l.tail = NULL;
        }
        free(p);
        l.elementcount--;
    }
    return l;
}

BF removeFactTail(BF l) {
    if (l.tail != NULL) {
        Proposition *p = l.tail;
        l.tail = l.tail -> previous;
        if (l.tail != NULL) {
            l.tail -> next = NULL;
        } else {
            l.head = NULL;
        }
        free(p);
        l.elementcount--;
    }
    return l;
}

Proposition accessBFHead(BF l) {
    if (l.head != NULL) {
        return *l.head;
    }
    return createConclusion('\0', false);   
}

void displayFacts(BF l) {
    if (l.head == NULL) {
        printf("Base de faits vide.\n");
        return;
    }
    Proposition *p = l.head;
    while (p != NULL) {
        printf("%c=%s\n", p -> name, p -> value ? "TRUE" : "FALSE");
        p = p -> next;
    }
}