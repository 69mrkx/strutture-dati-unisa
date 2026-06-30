#define MAXSTACK 100
#include <stdlib.h>
#include "../item/item.h"
#include "stack.h"

struct stack {
    Item elements[MAXSTACK];
    int top; // Indice del primo spazio vuoto
};

Stack newStack() {
    struct stack *s = malloc(sizeof(struct stack));
    if (s == NULL) return NULL;
    s->top = 0;
    return s;
}

int isEmptyStack(Stack s) {
    return s->top == 0 ? 1 : 0;
}

int push(Stack s, Item val) {
    if (s->top + 1 <= MAXSTACK - 1) {
        s->elements[s->top++] = val;
        return 0;
    }
    return 1;
}

Item pop(Stack s) {
    if (s->top - 1 >= 0) {
        return s->elements[--s->top];
    }
    return NULL;
}

Item top(Stack s) {
    if (s->top <= 0) return NULL;
    return s->elements[s->top - 1];
}