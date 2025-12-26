#ifndef INFERENCE_H
#define INFERENCE_H

#include "header.h"

/**
 * @brief ajoute les nouvelles propositions déduites dans la base de faits
 * 
 * @param knowledgeBase 
 * @param factBase 
 */
void inferenceEngine(BC *knowledgeBase, Premisse *factBase);

/**
 * @brief vérifie si toutes les prémisses d'une règle sont dans la base de faits
 * 
 * @param r règle à vérifier
 * @param factBase premisses de la base de faits

 * @return true 
 * @return false 
 */
bool areAllPremissesTrue(Rule r, Premisse factBase);

#endif