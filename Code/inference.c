#include "header.h"

void inferenceEngine(BC *knowledgeBase, Premisse *factBase) { //ajoute les nouvelles propositions déduites dans la base de faits
    bool newFactAdded;

    do {//tant qu'une nouvelle proposition a été ajoutée
        newFactAdded = false;
        BC *currentRule = knowledgeBase;

        while (currentRule != NULL) {//pour chaque règle de la base de connaissances
            Rule current = currentRule -> regle;

            if (areAllPremissesTrue(current, *factBase)) {//si toutes les prémisses de la règle sont dans la base de faits
                if (!isPropositionInPremisse(*factBase, current.conclusion)) {//si la conclusion n'est pas déjà dans la base de faits
                    addProposition(factBase, current.conclusion);
                    newFactAdded = true; //une nouvelle proposition a été ajoutée
                }
            }

            currentRule = currentRule -> next;
        }
    } while (newFactAdded);//sarrête lorsque plus aucune nouvelle proposition n'est ajoutée
}

bool areAllPremissesTrue(Rule r, Premisse factBase) {//vérifie si toutes les prémisses d'une règle sont dans la base de faits
    if (r.premisse == NULL)// si la règle n'a pas de prémisse, elle est toujours applicable
        return true;

    Proposition *req = r.premisse -> head;
    while (req != NULL) {//pour chaque prémisse de la règle
        if (!isPropositionInPremisse(factBase, req -> proposition))//si la prémisse n'est pas dans la base de faits
            return false;
        req = req -> next;
    }
    return true;//toutes les prémisses sont dans la base de faits
}