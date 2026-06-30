#pragma once

#include "../item/item.h"
typedef struct stack *Stack;
typedef struct node* Node;

Stack newStack(); //Crea uno stack vuoto
int isEmptyStack(Stack s); //Controlla se lo stack è vuoto
int push(Stack s, Item val); //Inserisce un elemento in cima allo stack 
Item pop(Stack s); //Rimuove e restituisce l'elemento in cima allo stack
Item top(Stack s); //Restituisce l'elemento in cima allo stack senza rimuoverlo