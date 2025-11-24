#include "library.h"
#include <stdlib.h>
#include <stdio.h>

ListofInteger createEmptyList() {
    ListofInteger l;
    l.head = NULL;
    l.tail = NULL;
    l.elementcount = 0;
    return l;
}

Element* newElement (int e, Element* next, Element* previous) {
    Element *newel = (Element *) malloc(sizeof(Element));
    newel -> value = e;
    newel -> next = next;
    newel -> previous = previous;
    return newel;
}

ListofInteger insertHead (ListofInteger l, int e) {
    Element *newel = newElement(e, l.head, NULL);
    if (l.head != NULL) {
        l.head -> previous = newel;
    }
    else {
        l.tail = newel;
    }
    l.head = newel;
    l.elementcount++;
    return l;
}

ListofInteger removeHead (ListofInteger l) {
    if (l.head != NULL) {
        Element *p = l.head;
        l.head = l.head -> next;
        if (l.head != NULL) {
            l.head -> previous = NULL;
        } else {
            l.tail = NULL;
        }
        free(p);
        l.elementcount--;
    }
    return l;
}

ListofInteger insertTail (ListofInteger l, int e) {
    Element *newel = newElement(e, NULL, NULL);
    if (l.head == NULL) {
        l.head = l.tail = newel;
        l.elementcount++;
    } else {
        l.tail -> next = newel;
        newel -> previous = l.tail;
        l.tail = newel;
        l.elementcount++;
    }
    return l;
}

ListofInteger removeTail (ListofInteger l) {
    if (l.tail != NULL) {
        Element *p = l.tail;
        l.tail = l.tail -> previous;
        if (l.tail != NULL) {
            l.tail -> next = NULL;
        } else {
            l.head = NULL;
        }
        free(p);
        l.elementcount--;
    }
    return l;
}

void display (ListofInteger l) {
    if (l.head == NULL) {
        printf("Liste vide.\n");
        return;
    }

    Element *p = l.head;
    while (p != NULL) {
        printf("%d ", p -> value);
        p = p -> next;
    }
    printf("\n");
}

ListofInteger emptyList (ListofInteger l) {
    if (l.head == NULL) {
        return l;
    }
    else {
        Element *p = l.head;
        Element *tmp = NULL;
        while (p != NULL) {
            tmp = p -> next;
            free(p);
            p = tmp;
        }
        l.head = NULL;
        l.tail = NULL;
        l.elementcount = 0;
    }
    return l;
}