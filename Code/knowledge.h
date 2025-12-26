#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include "header.h"

/**
 * @brief  Crée une base de connaissances vide
 * 
 * @return BC* (NULL)
 */
BC* createKnowledgeBase();

/**
 * @brief Ajoute une règle à la fin de la base de connaissances
 * 
 * @param knowledgeBase 
 * @param r règle à ajouter
 * @return BC* retourne la base de connaissances mise à jour
 */
BC* addRuleToKnowledgeBase(BC *knowledgeBase, Rule r);

/**
 * @brief Retourne la première règle de la base de connaissances
 * 
 * @param knowledgeBase 
 * @return Rule retourne la première règle de la base de connaissances ou NULL si la base est vide
 */
Rule headOfKnowledgeBase(BC *knowledgeBase);

/**
 * @brief Supprime toute la base de connaissances
 * 
 * @param knowledgeBase 
 */
void deleteKnowledgeBase(BC **knowledgeBase);

#endif