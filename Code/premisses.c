#include "header.h"

Premisse createPremisse() {// initialise une premisse vide
    Premisse p;
    p.head = NULL;
    return p;
}

bool isPropositionInPremisse(Premisse p, char *proposition) {// verifie si une proposition est dans une premisse
    Proposition *current = p.head;
    while (current != NULL) { // parcours la liste des propositions
        if (strcmp(current -> proposition, proposition) == 0)// compare la proposition courante avec celle recherchee
            return true;
        current = current -> next;
    }
    return false;
}

void removeProposition(Premisse *p, char *proposition) {// supprime une proposition d'une premisse
    Proposition *current = p -> head;
    Proposition *previous = NULL;

    while (current != NULL) {// parcourt la liste des propositions
        if (strcmp(current -> proposition, proposition) == 0) {// trouve la proposition a supprimer
            if (previous == NULL) {// si c'est la premiere proposition
                p -> head = current -> next;
            } else {// si c'est une proposition intermediaire ou la derniere
                previous -> next = current -> next;
            }
            free(current);
            return;
        }
        previous = current;// sauvegarde la proposition precedente
        current = current -> next; // passe a la proposition suivante
    }
}

bool isPremisseEmpty(Premisse p) {// verifie si une premisse est vide
    return p.head == NULL;
}

void addProposition(Premisse *p, char *proposition) {// ajoute une proposition a une premisse
    Proposition *newProp = malloc(sizeof(Proposition));
    strcpy(newProp -> proposition, proposition);// copie la proposition dans la nouvelle structure
    newProp -> next = NULL;

    if (p -> head == NULL) {// si la premisse est vide, ajoute la nouvelle proposition en tete
        p -> head = newProp;
    } else {// sinon, ajoute la nouvelle proposition a la fin de la liste
        Proposition *current = p -> head;
        while (current -> next != NULL) {// parcourt la liste jusqu'a la derniere proposition
            current = current -> next;
        }
        current -> next = newProp;
    }
}

Proposition accessPremisseHead(Premisse p) {// accede a la premiere proposition d'une premisse
    if (p.head != NULL) {// si la premisse n'est pas vide
        return *p.head; // retourne la premiere proposition
    } else {// si la premisse est vide, retourne une proposition vide
        Proposition emptyProp;
        strcpy(emptyProp.proposition, "");
        emptyProp.next = NULL;
        return emptyProp;// retourne une proposition vide
    }
}

void deletePremisse(Premisse *p) {// supprime toutes les propositions d'une premisse
    Proposition *current = p -> head;
    Proposition *next;

    while (current != NULL) {// parcourt la liste des propositions
        next = current -> next;
        free(current);
        current = next;
    }
    p -> head = NULL;
}
