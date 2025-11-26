/*
 * =============================================================================
 * Projet : Projet_LO21
 * Fichier : main.c
 * Auteur : Jean Delepine
 * =============================================================================
 */

#include "header.h"

BF addFact(BF facts) {
    char name;
    int value;
    printf("Fact name (ex: A) : ");
    scanf(" %c", &name);
    printf("Value (true, false) : ");
    scanf("%d", &value);

    Proposition p = createConclusion(name, value);
    facts = insertFactTail(facts, p);

    printf("Fact added : %c=%s\n", name, value ? "TRUE" : "FALSE");
    return facts;
}

BC addRule(BC knowledge) {
    Premisse prem = createEmptyPremisse();
    Proposition premProp;
    char name;
    int value;
    char cont;

    printf("Creation of a rule : IF ... THEN ...\n");

    do {
        printf("Name of the Premisse : ");
        scanf(" %c", &name);
        printf("Value (true, false) : ");
        scanf("%d", &value);

        premProp = createConclusion(name, value);
        prem = addPropTail(prem, premProp);

        printf("Add another Premisse ? (y/n) : ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');

    printf("Name of the conclusion : ");
    scanf(" %c", &name);
    printf("Value (true, false) : ");
    scanf("%d", &value);

    Proposition conclusion = createConclusion(name, value);

    Regle r = createEmptyRule();
    r.premisse = prem;
    r.conclusion = conclusion;

    knowledge = insertRuleTail(knowledge, r);

    printf("Rule added\n");
}

int main(void){
    BF facts = createEmptyBF();
    BC knowledge = createEmptyBC();
    for (;;) {
        printf("Welcome to the Inference Engine\n");
        printf("1. Add rule to knowledge base\n");
        printf("2. Add fact to fact base\n");
        printf("3. Deduce new facts\n");
        printf("4. Show rules\n");
        printf("5. Show facts\n");
        printf("6. Empty rule base\n");
        printf("7. Empty fact base\n");
        printf("8. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                knowledge = (knowledge);
                break;
            case 2:
                facts = addFact(facts);
                break;
            case 3:
                BF deducted = deduceFacts(facts, knowledge);
                displayFacts(deducted);
                break;
            case 4:
                displayRules(knowledge);
                break;
            case 5:
                displayFacts(facts);
                break;
            case 6:
                knowledge = emptyBC(knowledge);
                printf("Knowledge base emptied.\n");
                break;
            case 7:
                facts = emptyBF(facts);
                printf("Fact base emptied.\n");
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }  
}