#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct prop {
    char proposition[32];
    struct prop *next;
} Proposition;

typedef struct {
    Proposition *head;
} Premisse;

typedef struct {
    Premisse *premisse;
    char conclusion[32];
} Rule;

typedef struct BC {
    Rule regle;
    struct BC *next;
} BC;

#endif