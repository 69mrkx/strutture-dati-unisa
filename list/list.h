#pragma once
#include "../item/item.h"
typedef struct list *List;

// Costruttore: crea una lista vuota
List newList();
//Controlla se la lista è vuota
int isEmptyList(List);
// Inserimento in testa: O(1)
void addHead(List, Item);
// Inserimento in coda: O(n)
void addTail(List, Item);

// Inserimento ordinato (richiede compareItem): O(n)
//void addSortedList(List, Item);

// Rimozione per valore: O(n)
int removeValue(List, Item);
// Ricerca dell'indice (posizione) di un elemento: O(n)
int lookup(List, Item);
//Elimina tutti gli elementi della lista e libera la memoria
void freeList(List);
// Stampa tutti gli elementi della lista
void outputList(List);
//Rimuove il primo elemento della lista e ritorna il valore
Item removeHead(List);
//Ritorna il primo elemento della lista
Item getHead(List);