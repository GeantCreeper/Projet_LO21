#include "header.h"

int main(void) {
    Premisse factBase = createPremisse();
    BC *knowledgeBase = createKnowledgeBase();

    for (;;) {
        printf("Welcome to the Inference Engine\n");
        printf("1. Add rule to knowledge base\n");
        printf("2. Add fact to fact base\n");
        printf("3. Deduce new facts\n");
        printf("4. Show facts\n");
        printf("5. Show rules\n");
        printf("6. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRule(&knowledgeBase);
                break;

            case 2:
                addFact(&factBase);
                break;

            case 3:
                inferenceEngine(knowledgeBase, &factBase);
                printf("Inference completed.\n");
                break;

            case 4: {
                printf("Facts:\n");
                Proposition *p = factBase.head;
                while (p != NULL) {
                    printf("- %s\n", p -> proposition);
                    p = p -> next;
                }
                break;
            }

            case 5: {
                printf("Rules:\n");
                BC *curr = knowledgeBase;
                while (curr != NULL) {
                    Rule r = curr -> regle;
                    printf("IF ");
                    Proposition *prop = r.premisse -> head;
                    while (prop != NULL) {
                        printf("%s", prop -> proposition);
                        if (prop->next != NULL) printf(" AND ");
                        prop = prop -> next;
                    }
                    printf(" THEN %s\n", r.conclusion);
                    curr = curr -> next;
                }
                break;
            }

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

