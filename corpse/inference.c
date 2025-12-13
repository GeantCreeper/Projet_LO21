#include "header.h"

void inferenceEngine(BC *knowledgeBase, Premisse *factBase) {
    bool newFactAdded;

    do {
        newFactAdded = false;
        BC *currentRuleNode = knowledgeBase;

        while (currentRuleNode != NULL) {
            Rule currentRule = currentRuleNode -> regle;

            if (areAllPremissesTrue(currentRule, *factBase)) {
                if (!isPropositionInPremisse(*factBase, currentRule.conclusion)) {
                    addProposition(factBase, currentRule.conclusion);
                    newFactAdded = true;
                }
            }

            currentRuleNode = currentRuleNode -> next;
        }
    } while (newFactAdded);
}

bool areAllPremissesTrue(Rule r, Premisse factBase) {
    if (r.premisse == NULL)
        return true;

    Proposition *req = r.premisse->head;
    while (req != NULL) {
        if (!isPropositionInPremisse(factBase, req->proposition))
            return false;
        req = req->next;
    }
    return true;
}