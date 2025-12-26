#include "header.h"

BC* createKnowledgeBase() {// Crée une base de connaissances vide
    return NULL;
}

BC* addRuleToKnowledgeBase(BC *knowledgeBase, Rule r) {// Ajoute une règle à la fin de la base de connaissances
    BC *newRule = malloc(sizeof(BC));
    newRule -> regle = r;
    newRule -> next = NULL;

    if (knowledgeBase == NULL)// Si la base de connaissances est vide, on ajoute la première règle
        return newRule;
    else {// Sinon, on parcourt la liste jusqu'à la fin et on ajoute la nouvelle règle
        BC *tmp = knowledgeBase;
        while (tmp->next != NULL)
            tmp = tmp -> next;
        tmp -> next = newRule;
        return knowledgeBase;
    }
}

Rule headOfKnowledgeBase(BC *knowledgeBase) {// Retourne la première règle de la base de connaissances
    if (knowledgeBase == NULL) { // Si la base de connaissances est vide, on retourne une règle vide
        Rule empty = createRule();
        return empty;
    }
    return knowledgeBase -> regle;// Retourne la première règle
}

void deleteKnowledgeBase(BC **knowledgeBase) {// Supprime toute la base de connaissances
    BC *current = *knowledgeBase;
    BC *next;

    while (current != NULL) { // Parcourt toute la liste et libère la mémoire
        next = current -> next;
        deleteRule(&current -> regle);
        free(current);
        current = next;
    }

    *knowledgeBase = NULL;// Met à jour le pointeur de la base de connaissances à NULL
}