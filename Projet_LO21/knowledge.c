/*
 * =============================================================================
 * Projet : Projet_LO21
 * Fichier : knowledge.c
 * Auteur : Jean Delepine
 * =============================================================================
 */

#include "header.h"

deduceFacts(BF facts, BC knowledgeBase) { 
    BF deducted, fact_base;
    BC knowledge_base;
    for (int i = 0; i < fact_base.elementcount; i++) {
        for (int j = 0; j < knowledge_base.elementcount; j++) {
            if (fact_base.head -> name == knowledge_base.head -> premisse.head -> name) {
                
                if (isPremisseEmpty(knowledge_base.head -> premisse)) {
                    insertFactTail(fact_base, knowledge_base.head -> conclusion);
                    insertFactTail(deducted, knowledge_base.head -> conclusion);
                }
            }
        }
    }
}
