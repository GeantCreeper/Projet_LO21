#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

#include "rules.h"
#include "knowledge.h"
#include "premisses.h"
#include "inference.h"

#endif