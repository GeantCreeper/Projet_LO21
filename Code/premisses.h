#ifndef PREMISSES_H
#define PREMISSES_H

#include "header.h"

/**
 * @brief initialise une premisse vide
 * 
 * @return Premisse 
 */
Premisse createPremisse();

/**
 * @brief verifie si une proposition est dans une premisse
 * 
 * @param p premisse
 * @param proposition 

 * @return true si dans la premisse
 * @return false sinon
 */
bool isPropositionInPremisse(Premisse p, char *proposition);

/**
 * @brief supprime une proposition d'une premisse
 * 
 * @param p premisse
 * @param proposition 
 */
void removeProposition(Premisse *p, char *proposition);

/**
 * @brief verifie si une premisse est vide
 * 
 * @param p premisse
 * @return true 
 * @return false 
 */
bool isPremisseEmpty(Premisse p);

/**
 * @brief ajoute une proposition a une premisse
 * 
 * @param p premisse
 * @param proposition 
 */
void addProposition(Premisse *p, char *proposition);

/**
 * @brief  accede a la premiere proposition d'une premisse
 * 
 * @param p premisse
 * @return Proposition : head si premisse non vide, vide si premisse vide
 */

Proposition accessPremisseHead(Premisse p);

/**
 * @brief supprime toutes les propositions d'une premisse
 * 
 * @param p premisse
 */
void deletePremisse(Premisse *p);

#endif