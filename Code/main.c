// Déclaration des fonctions
#include "header.h"
void addRule(BC **knowledgeBase);
void addFact(Premisse *factBase);

int main(void) {
    // Initialisation des bases de faits et de connaissances
    Premisse factBase = createPremisse();
    BC *knowledgeBase = createKnowledgeBase();

    for (;;) { // Boucle infinie pour le menu
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
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Vide le tampon
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        switch (choice) {
            case 1:// Ajouter une règle
                addRule(&knowledgeBase);  // Appel de la fonction pour ajouter une règle
                break;

            case 2:// Ajouter un fait
                addFact(&factBase);  // Appel de la fonction pour ajouter un fait
                break;

            case 3:// Effectuer l'inférence
                inferenceEngine(knowledgeBase, &factBase);
                printf("Inference completed.\n");
                break;

            case 4: // Afficher les règles
            {
                printf("Rules:\n");
                BC *curr = knowledgeBase;
                while (curr != NULL) {// Parcourir la base de connaissances
                    Rule r = curr -> regle; // Récupérer la règle courante
                    printf("IF ");
                    Proposition *prop = r.premisse -> head;
                    while (prop != NULL) {// Parcourir les prémisses
                        printf("%s", prop -> proposition);
                        if (prop -> next != NULL) printf(" AND ");
                        prop = prop -> next; // Aller à la prémisse suivante
                    }
                    printf(" THEN %s\n", r.conclusion);// Afficher la conclusion
                    curr = curr -> next; // Aller à la règle suivante
                }
                break;
            }

            case 5:// Afficher les faits
            {
                printf("Facts:\n");
                Proposition *p = factBase.head; // Récupérer la tête de la liste des faits
                while (p != NULL) {// Parcourir les faits
                    printf("- %s\n", p -> proposition);
                    p = p -> next;
                }
                break;
            }
            
            case 6: //  Supprimer les règles
            {
                deleteKnowledgeBase(&knowledgeBase);// Supprimer toutes les règles de la base de connaissances
                printf("All rules have been deleted.\n");
                break;
            }

            case 7:// Supprimer les faits
            {
                deletePremisse(&factBase);// Supprimer tous les faits de la base de faits
                printf("All facts have been deleted.\n");
                break;
            }

            case 8:// Quitter le programme
                printf("Exiting...\n");
                return 0;

            default:// Option invalide
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
        // Vide le tampon
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

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
