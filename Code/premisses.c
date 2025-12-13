#include "header.h"

Premisse createPremisse() {
    Premisse p;
    p.head = NULL;
    return p;
}

bool isPropositionInPremisse(Premisse p, char *proposition) {
    Proposition *current = p.head;
    while (current != NULL) {
        if (strcmp(current->proposition, proposition) == 0)
            return true;
        current = current->next;
    }
    return false;
}

void removeProposition(Premisse *p, char *proposition) {
    Proposition *current = p->head;
    Proposition *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->proposition, proposition) == 0) {
            if (previous == NULL) {
                p->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

bool isPremisseEmpty(Premisse p) {
    return p.head == NULL;
}

void addProposition(Premisse *p, char *proposition) {
    Proposition *newProp = malloc(sizeof(Proposition));
    strcpy(newProp->proposition, proposition);
    newProp->next = NULL;

    if (p->head == NULL) {
        p->head = newProp;
    } else {
        Proposition *current = p->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newProp;
    }
}

Proposition accessPremisseHead(Premisse p) {
    if (p.head != NULL) {
        return *(p.head);
    } else {
        Proposition emptyProp;
        strcpy(emptyProp.proposition, "");
        emptyProp.next = NULL;
        return emptyProp;
    }
}

