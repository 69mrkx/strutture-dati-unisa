#include <stdlib.h>
#include <stdio.h>

#include "../utils.h"
#include "../item/item.h"
#include "list.h"


// Definizione in list.c (nascosta al client)
struct node {
    Item value;        // Valore generico (ADT Item)
    struct node *next; // Puntatore al nodo successivo
};

struct list {
    int size;          // Dimensione della lista
    struct node *head; // Puntatore al primo nodo
};


// Costruttore: crea una lista vuota
List newList() {
    List l = malloc(sizeof(struct list));
    if(l != NULL){
        l->size = 0;
        l->head = NULL;
    }
    return l;
}

int isEmptyList(List l) {
    if(l == NULL) return 1;
    return (l->head == NULL); 
}

// Inserimento in testa: O(1)
void addHead(List l, Item val) {

    struct node *new_node = malloc(sizeof(struct node));
    if(new_node == NULL) return; 

    new_node->value = val;
    new_node->next = l->head;
    l->head = new_node;
    l->size++;
}

// Inserimento in coda: O(n)
void addTail(List l, Item val) {
    struct node *new_node = malloc(sizeof(struct node));
    if(new_node == NULL) return;

    new_node->value = val;
    new_node->next = NULL; 

    if( l-> head == NULL )l->head = new_node;
    else{
        struct node *current = l->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node; 
    }
    l->size++;
}

// Inserimento ordinato (richiede compareItem): O(n)
//void addSorted(List l, Item val) {}

// Rimozione per valore: O(n)
int removeValue(List l, Item val) {
    struct node *prev = NULL;
    struct node *curr = l->head;

    while(curr != NULL && compareItem(curr->value, val) != 0){
    }
    if(curr == NULL) return 0;
    if(prev == NULL){
        l->head = curr->next;
    }else{
        prev->next = curr->next;
    }

    //Libero la memoria
    freeItem(curr->value);
    free(curr);
    l->size--;

    return 1;
}

// Ricerca dell'indice (posizione) di un elemento: O(n)
int lookup(List l, Item val) {
    struct node *curr = l->head;
    int pos = 0;
    while(curr != NULL){
        if(compareItem(curr->value, val) == 0){
            return pos;
        }
        curr = curr->next;
        pos++;
    }
    return -1;
}

void freeList(List l) {
    struct node *curr = l->head;
    while(curr != NULL){
        struct node *temp = curr;
        curr = curr->next;
        freeItem(temp->value);
        free(temp);
    }
    free(l);
}

void outputList(List l) {
    struct node *curr = l->head;
    while(curr != NULL){
        outputItem(curr->value);
        printf(" -> ");
        curr = curr->next;
    }
}

Item removeHead(List l){
    Item ret = l->head->value;
    if(!isEmptyList(l)){
        struct node *temp = l->head;
        l->head = temp;
        free(temp);
    }
    return ret;
}

Item getHead(List l){
    return l->head->value;
}