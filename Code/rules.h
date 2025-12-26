#ifndef RULES_H
#define RULES_H

#include "header.h"

/**
 * @brief alloue memoire pour une regle et initialise ses champs
 * 
 * @return Rule 
 */
Rule createRule();

/**
 * @brief ajoute une proposition a la premisse d'une regle
 * 
 * @param r 
 * @param proposition 
 */
void addPropositionToPremisse(Rule *r, char *proposition);

/**
 * @brief cree l'objet conclusion d'une regle
 * 
 * @param r 
 * @param proposition 
 */
void createConclusion(Rule *r, char *proposition);

/**

 * @brief renvoie la conclusion d'une regle
 * 
 * @param r 
 * @return char* conclusion de la regle
 */
char *accessConclusion(Rule r);

/**
 * @brief libere la memoire allouee pour une regle et ses champs
 * 
 * @param r 
 */
void deleteRule(Rule *r);

#endif