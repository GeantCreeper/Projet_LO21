/*
 * =============================================================================
 * Projet : Projet_LO21
 * Fichier : rules.c
 * Auteur : Jean Delepine
 * =============================================================================
 */

#include "header.h"

Proposition* newProposition(char name, bool value, Proposition* next, Proposition* previous) {
    Proposition *newel = (Proposition *) malloc(sizeof(Proposition));
    newel -> name = name;
    newel -> value = value;
    newel -> next = next;
    newel -> previous = previous;
    return newel;
}

bool isPropositionInPremisse(Premisse p, char name) {
    /* cas de base : liste vide */
    if (p.head == NULL) {
        return false;
    }
    if (p.head->name == name) {
        return true;
    }
    /* construire une vue sur le reste de la liste sans la tête et rappeler la même fonction */
    Premisse rest = p;
    rest.head = p.head -> next;
    return isPropositionInPremisse(rest, name);
}

Proposition createConclusion(char name, bool value){
    Proposition conclusion;
    conclusion.name = name;
    conclusion.value = value;
    conclusion.next = NULL;
    conclusion.previous = NULL;
    return conclusion;
}

Proposition accessConclusion(BC rules, char name) {
    while (rules.head ->conclusion.name != name){
        rules.head = rules.head -> next;
    }
    return rules.head -> conclusion;
}

Premisse createEmptyPremisse(void) {
    Premisse p;
    p.head = NULL;
    p.tail = NULL;
    p.elementcount = 0;
    return p;
}

Premisse emptyPremisse(Premisse p) {
    if (p.head == NULL) {
        return p;
    }
    else {
        Proposition *l = p.head;
        Proposition *tmp = NULL;
        while (l != NULL) {
            tmp = l -> next;
            free(l);
            l = tmp;
        }
        p.head = NULL;
        p.tail = NULL;
        p.elementcount = 0;
    }
    return p;
}

Premisse addPropTail(Premisse p, Proposition prop){
    Proposition *newel = newProposition(prop.name, prop.value, NULL, NULL);
    if (p.head == NULL) {
        p.head = p.tail = newel;
        p.elementcount++;
    } else {
        p.tail -> next = newel;
        newel -> previous = p.tail;
        p.tail = newel;
        p.elementcount++;
    }
    return p;
}

Premisse removeProposition(Premisse p, char name){
    Proposition *current = p.head;
    while (current != NULL) {
        if (current -> name == name) {
            if (current -> previous != NULL) {
                current -> previous -> next = current -> next;
            } else {
                p.head = current -> next;
            }
            if (current -> next != NULL) {
                current -> next -> previous = current -> previous;
            } else {
                p.tail = current -> previous;
            }
            free(current);
            p.elementcount--;
            return p;
        }
        current = current -> next;
    }
    return p;
}

bool isPremisseEmpty(Premisse p) {
    if (p.elementcount == 0) {
        return true;
    }
    return false;
}

Proposition accessPremisseHead(Premisse p) {
    if (p.head != NULL) {
        return *p.head;
    }
    return *newProposition('\0', false, NULL, NULL);
}

Regle* newRule(const Premisse pre, const Proposition c, Regle* next, Regle* previous) {
    Regle *newel = (Regle *) malloc(sizeof(Regle));
    newel -> premisse = pre;
    newel -> conclusion = c;
    newel -> next = next;
    newel -> previous = previous;
    return newel;
}

Regle createEmptyRule(void) {
    Regle r;
    r.premisse = createEmptyPremisse();
    r.conclusion = createConclusion('\0', false);
    r.next = NULL;
    r.previous = NULL;
    return r;
}

BC createEmptyBC(void) {
    BC l;
    l.head = NULL;
    l.tail = NULL;
    l.elementcount = 0;
    return l;
}

BC emptyBC(BC l) {
    if (l.head == NULL) {
        return l;
    }
    else {
        Regle *r = l.head;
        Regle *tmp = NULL;
        while (r != NULL) {
            tmp = r -> next;
            free(r);
            r = tmp;
        }
        l.head = NULL;
        l.tail = NULL;
        l.elementcount = 0;
    }
    return l;
}

BC insertRuleTail(BC l, Regle r) {
    Regle *newel = newRule(r.premisse, r.conclusion, NULL, NULL);
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

BC removeRuleHead(BC l) {
    if (l.head != NULL) {
        Regle *p = l.head;
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

BC removeRuleTail(BC l) {
    if (l.tail != NULL) {
        Regle *p = l.tail;
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

Regle accessBCHead(BC l) {
    if (l.head != NULL) {
        return *l.head;
    }
    return createEmptyRule();
}

void displayRules(BC l) {
    if (l.head == NULL) {
        printf("Base de connaissances vide.\n");
        return;
    }

    Regle *r = l.head;
    while (r != NULL) {
        printf("Rule : IF ");
        Proposition *p = r -> premisse.head;
        while (p != NULL) {
            printf("%c=%s ", p -> name, p -> value ? "TRUE" : "FALSE");
            p = p -> next;
            if (p != NULL) {
                printf("AND ");
            }
        }
        printf("-> %c=%s\n", r -> conclusion.name, r -> conclusion.value ? "TRUE" : "FALSE");
        r = r -> next;
    }
}