/*
 * =============================================================================
 * Projet : Projet_LO21
 * Fichier : main.c
 * Auteur : Jean Delepine
 * =============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "rules.h"
#include "knowledge.h"

int main(void){
    bool deducted = NULL;
    for (;;){
        printf("Welcome to the Inference Engine\n");
        printf("1. Add fact to knowledge base\n");
        printf("2. Deduce new facts\n");
        printf("3. Show knowledge base\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Add fact to knowledge base
                break;
            case 2:
                // Deduce new facts
                break;
            case 3:
                // Show knowledge base
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }  
}