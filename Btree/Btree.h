#include "../item/item.h"
typedef struct node *Btree;

Btree newBtree(void);
int isEmptyBtree(Btree);
Btree buildBtree(Btree, Btree, Item);
Item getBtreeRoot(Btree);
Btree getLeft(Btree);
Btree getRight(Btree);
Item getRoot(Btree);

void preorderPrint(Btree);
void inorderPrint(Btree);
void postorderPrint(Btree);
Btree getNodeByIndex(Btree, int);

// --- NUOVE FUNZIONI PER L'HEAP ---
Item getBtreeRoot(Btree);
void setBtreeRoot(Btree, Item);
void setLeft(Btree, Btree);
void setRight(Btree, Btree);