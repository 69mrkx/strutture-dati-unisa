#pragma once

// Item è definito come puntatore generico (void*) o puntatore ad una struct specifica
typedef void *Item;

// Prototipi degli operatori generici per Item
Item inputItem(void);
void outputItem(Item it);
int compareItem(Item it1, Item it2); // Ritorna: 0 se uguali, <0 se it1 < it2, >0 se it1 > it2
Item cloneItem(Item it);             // Effettua la copia profonda dell'oggetto
void freeItem(Item it);              // Fondamentale per deallocare memoria interna dell'Item
