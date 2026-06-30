#include "../item/item.h"

typedef struct heap *Heap;



Heap createHeap();
int getSizeHeap();
void siftUp(Heap, int);
void siftDown(Heap, int);

int insertHeap(Heap, Item);
Item extractMax(Heap);

void heapsort(Item *, int);
void heapify(Item *, int);
void heapify_tree(Heap , Item *, int);
