#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

typedef struct elem {
    int value;
    struct elem *next;
    struct elem *previous;
} Element;

typedef struct {
    Element *head;
    Element *tail;
    int elementcount;
} ListofInteger;

ListofInteger createEmptyList ();
Element* newElement (int e, Element* next, Element* previous);
ListofInteger insertHead (ListofInteger l, int e);
ListofInteger removeHead (ListofInteger l);
ListofInteger insertTail (ListofInteger l, int e);
ListofInteger removeTail (ListofInteger l);
void display (ListofInteger l);
ListofInteger emptyList (ListofInteger l);

#endif //LIBRARY_LIBRARY_H