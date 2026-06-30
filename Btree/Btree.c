#include <stdlib.h>
#include "Btree.h"
#include "../item/item.h"


struct node{
    Item value;
    struct node *left;
    struct node *right;
};


Btree newBtree(void){
    return NULL;
}

int isEmptyBtree(Btree t){
    return (t==NULL);
}

Btree buildBtree(Btree left, Btree right, Item e){
    Btree t = malloc(sizeof(struct node));
    if(t == NULL) return NULL;
    t->value = e;
    t->left = left;
    t->right = right;

    return t;
}

Item getRoot(Btree t){
    if(isEmptyBtree(t)) return NULL;
    return t->value;
}

Btree getLeft(Btree t){
    return isEmptyBtree(t) ? NULL : t->left;
}

Btree getRight(Btree t){
    return isEmptyBtree(t) ? NULL : t->right;
}


void preorderPrint(Btree t){
    if(t == NULL) return;
    outputItem(t->value);
    preorderPrint(t->left);
    preorderPrint(t->right);
}

void inorderPrint(Btree t){
    if(t == NULL) return;
    inorderPrint(t->left);
    outputItem(t->value);
    inorderPrint(t->right);

}

void postorderPrint(Btree t){
    if(t == NULL) return;
    postorderPrint(t->left);
    postorderPrint(t->right);
    outputItem(t->value);
}

Btree getNodeByIndex(Btree root, int index) {
    if (root == NULL) return NULL;
    
    int pos = index + 1; // Convertiamo in 1-based index
    
    // Troviamo il bit più significativo (MSB)
    int msb = 1;
    while ((msb << 1) <= pos) {
        msb <<= 1;
    }
    
    msb >>= 1; // Ignoriamo il primo bit che rappresenta la radice
    Btree curr = root;
    
    // Scendiamo nell'albero seguendo i bit
    while (msb > 0 && curr != NULL) {
        if (pos & msb) {
            curr = getRight(curr); // Bit 1 -> Destra
        } else {
            curr = getLeft(curr);  // Bit 0 -> Sinistra
        }
        msb >>= 1;
    }
    return curr;
}


// Questa sostituisce o affianca la tua vecchia getRoot
Item getBtreeRoot(Btree t){
    if(isEmptyBtree(t)) return NULL;
    return t->value;
}

void setBtreeRoot(Btree t, Item e) {
    if (!isEmptyBtree(t)) {
        t->value = e;
    }
}

void setLeft(Btree t, Btree leftChild) {
    if (!isEmptyBtree(t)) {
        t->left = leftChild;
    }
}

void setRight(Btree t, Btree rightChild) {
    if (!isEmptyBtree(t)) {
        t->right = rightChild;
    }
}