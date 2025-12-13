#ifndef INFERENCE_H
#define INFERENCE_H

#include "header.h"

void inferenceEngine(BC *knowledgeBase, Premisse *factBase);
bool areAllPremissesTrue(Rule r, Premisse factBase);

#endif