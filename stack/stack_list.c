#define MAXSTACK 100

#include <stdlib.h>
#include "../list/list.h"
#include "../item/item.h"
#include "stack.h"

struct stack {
    List elements;
};

Stack newStack() {
    struct stack* new_stack = malloc(sizeof(struct stack));
    new_stack->elements = newList();
    return new_stack;
}

int isEmptyStack(Stack s) {
    return isEmptyList(s->elements);
}

int push(Stack s, Item val) {
    addHead(s->elements, val);
    return 0;
}

Item pop(Stack s) {
    if(isEmptyStack(s)) return NULL;
    return removeHead(s->elements);
}

Item top(Stack s) {
    return getHead(s->elements);
}