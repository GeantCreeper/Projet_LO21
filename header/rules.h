#ifndef RULES_H
#define RULES_H

#include "header.h"

Rule createRule();
void addPropositionToPremisse(Rule *r, char *proposition);
void createConclusion(Rule *r, char *proposition);
char *accessConclusion(Rule r);

#endif