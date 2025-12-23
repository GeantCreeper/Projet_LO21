// Déclaration des fonctions
#include "header.h"
void addRule(BC **knowledgeBase);
void addFact(Premisse *factBase);

int main(void) {
    Premisse factBase = createPremisse();
    BC *knowledgeBase = createKnowledgeBase();

    for (;;) {
        printf("\nWelcome to the Inference Engine\n");
        printf("1. Add rule to knowledge base\n");
        printf("2. Add fact to fact base\n");
        printf("3. Deduce new facts\n");
        printf("4. Show rules\n");
        printf("5. Show facts\n");
        printf("6. Delete rules\n");
        printf("7. Delete facts\n");
        printf("8. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRule(&knowledgeBase);  // Appel de la fonction pour ajouter une règle
                break;

            case 2:
                addFact(&factBase);  // Appel de la fonction pour ajouter un fait
                break;

            case 3:
                inferenceEngine(knowledgeBase, &factBase);
                printf("Inference completed.\n");
                break;

            case 4: {
                printf("Rules:\n");
                BC *curr = knowledgeBase;
                while (curr != NULL) {
                    Rule r = curr -> regle;
                    printf("IF ");
                    Proposition *prop = r.premisse -> head;
                    while (prop != NULL) {
                        printf("%s", prop -> proposition);
                        if (prop -> next != NULL) printf(" AND ");
                        prop = prop -> next;
                    }
                    printf(" THEN %s\n", r.conclusion);
                    curr = curr -> next;
                }
                break;
            }

            case 5: {
                printf("Facts:\n");
                Proposition *p = factBase.head;
                while (p != NULL) {
                    printf("- %s\n", p -> proposition);
                    p = p -> next;
                }
                break;
            }
            
            case 6: {
                deleteKnowledgeBase(&knowledgeBase);
                printf("All rules have been deleted.\n");
                break;
            }

            case 7: {
                deletePremisse(&factBase);
                printf("All facts have been deleted.\n");
                break;
            }

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

// Implémentation de addRule
void addRule(BC **knowledgeBase) {
    Rule newRule = createRule();  // Créer une nouvelle règle
    char premise[32];
    char addMorePremises;

    // Ajouter des prémisses à la règle avec une boucle do-while
    do {
        printf("Enter premise: ");
        scanf("%s", premise);  // Demander la prémisse
        addPropositionToPremisse(&newRule, premise);  // Ajouter la prémisse à la règle

        // Demander à l'utilisateur s'il veut ajouter une autre prémisse
        printf("Do you want to add another premise? (y/n): ");
        scanf(" %c", &addMorePremises);  // Notez l'espace avant %c pour consommer les espaces ou sauts de ligne restants dans le tampon

    } while (addMorePremises == 'y' || addMorePremises == 'Y');

    // Ajouter une conclusion à la règle
    char conclusion[32];
    printf("Enter conclusion: ");
    scanf("%s", conclusion);
    createConclusion(&newRule, conclusion);  // Ajouter la conclusion à la règle

    // Ajouter la règle à la base de connaissances
    *knowledgeBase = addRuleToKnowledgeBase(*knowledgeBase, newRule);
}


// Implémentation de addFact
void addFact(Premisse *factBase) {
    char fact[32];
    printf("Enter fact: ");
    scanf("%s", fact);
    addProposition(factBase, fact);  // Ajouter le fait à la base de faits
}
