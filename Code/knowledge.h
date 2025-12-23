#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include "header.h"

BC* createKnowledgeBase();
BC* addRuleToKnowledgeBase(BC *knowledgeBase, Rule r);
Rule headOfKnowledgeBase(BC *knowledgeBase);
void deleteKnowledgeBase(BC **knowledgeBase);

#endif