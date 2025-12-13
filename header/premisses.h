#ifndef PREMISSES_H
#define PREMISSES_H

#include "header.h"

Premisse createPremisse();
bool isPropositionInPremisse(Premisse p, char *proposition);
void removeProposition(Premisse *p, char *proposition);
bool isPremisseEmpty(Premisse p);
void addProposition(Premisse *p, char *proposition);
Proposition accessPremisseHead(Premisse p);

#endif