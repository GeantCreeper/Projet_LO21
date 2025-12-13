/*
 * =============================================================================
 * Projet : Projet_LO21
 * Fichier : knowledge.c
 * Auteur : Jean Delepine
 * =============================================================================
 */

#include "header.h"

BF deduceFacts(BF facts, BC knowledge) {
    BF deducted = createEmptyBF();
    Regle *r = knowledge.head;
    while (r != NULL) {
        Proposition *p = r->premisse.head;
        bool state = true;

        while (p != NULL) {
            if (!isPropositionInPremisse(
                    (Premisse){facts.head, facts.tail, facts.elementcount},
                    p->name)) {
                state = false;
                break;
            }
            p = p->next;
        }
        if (state) {
            facts = insertFactTail(facts, r->conclusion);
            deducted = insertFactTail(deducted, r->conclusion);
        }
        r = r->next;
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
    Proposition *newel = newProposition(p.name, NULL, NULL);
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
    return createConclusion('\0');   
}

void displayFacts(BF l) {
    if (l.head == NULL) {
        printf("Base de faits vide.\n");
        return;
    }
    Proposition *p = l.head;
    while (p != NULL) {
        printf("%c\n", p -> name);
        p = p -> next;
    }
}