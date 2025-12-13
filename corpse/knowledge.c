#include "header.h"

BC* createKnowledgeBase() {
    return NULL;
}

BC* addRuleToKnowledgeBase(BC *knowledgeBase, Rule r) {
    BC *newRule = malloc(sizeof(BC));
    newRule -> regle = r;
    newRule -> next = NULL;

    if (knowledgeBase == NULL)
        return newRule;
    else {
        BC *tmp = knowledgeBase;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp -> next = newRule;
        return knowledgeBase;
    }
}

Rule headOfKnowledgeBase(BC *knowledgeBase) {
    if (knowledgeBase == NULL) {
        Rule empty = createRule();
        return empty;
    }
    return knowledgeBase -> regle;
}