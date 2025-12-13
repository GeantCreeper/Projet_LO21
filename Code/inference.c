#include "header.h"

void inferenceEngine(BC *knowledgeBase, Premisse *factBase) {
    bool newFactAdded;

    do {
        newFactAdded = false;
        BC *currentRule = knowledgeBase;

        while (currentRule != NULL) {
            Rule current = currentRule -> regle;

            if (areAllPremissesTrue(current, *factBase)) {
                if (!isPropositionInPremisse(*factBase, current.conclusion)) {
                    addProposition(factBase, current.conclusion);
                    newFactAdded = true;
                }
            }

            currentRule = currentRule-> next;
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