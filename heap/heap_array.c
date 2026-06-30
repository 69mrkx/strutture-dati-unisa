#include <stdlib.h>
#include "../item/item.h"
#include "heap.h"
#include "../utils.h"

struct heap {
    Item *elements;
    int size;
    int max_size;
};

void siftUp(Heap h, int i){
    while (i > 0) {
        int p = (i - 1) / 2; // Indice del padre
        if (compareItem(h->elements[i], h->elements[p]) > 0) {
            // Scambio figlio e padre
            swap(h->elements[i], h->elements[p]);
            i = p; // Continuo dal padre
        } else {
            break; // Proprietà rispettata
        }
    }
}

void siftDown(Heap h, int i) {
    int left, right, max_idx;
    while (2 * i + 1 < h->size) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        max_idx = i;
        
        // Trova il maggiore tra il nodo corrente, figlio sinistro e figlio destro
        if (compareItem(h->elements[left], h->elements[max_idx]) > 0) {
            max_idx = left;
        }
        if (right < h->size && compareItem(h->elements[right], h->elements[max_idx]) > 0) {
            max_idx = right;
        }
        
        if (max_idx != i) {
            // Scambio
            Item temp = h->elements[i];
            h->elements[i] = h->elements[max_idx];
            h->elements[max_idx] = temp;
            i = max_idx; // Continuo la discesa dal figlio scambiato
        } else {
            break; // Proprietà rispettata
        }
    }
}


int insertHeap(Heap h, Item e) {
    if (h->size >= h->max_size) {
        return 0; // Coda piena (Overflow)
    }
    h->elements[h->size] = e;
    h->size++;
    siftUp(h, h->size - 1);
    return 1;
}

Item extractMax(Heap h) {
    if (h->size == 0) {
        return NULL; // Coda vuota
    }
    Item max_val = h->elements[0]; // Salvo la radice
    h->elements[0] = h->elements[h->size - 1]; // Sposto l'ultimo in radice
    h->size--;
    siftDown(h, 0); // Ripristino proprietà con siftDown
    return max_val;
}

void heapsort(Item *arr, int n) {
    // 1. Crea il max-heap in O(n)
    heapify(arr, n);
    
    struct heap temp_heap;
    temp_heap.elements = arr;
    temp_heap.size = n;
    temp_heap.max_size = n;
    
    // 2. Estrae gli elementi uno per uno
    for (int i = n - 1; i > 0; i--) {
        // Scambio il massimo corrente con l'ultimo elemento
        Item temp = temp_heap.elements[0];
        temp_heap.elements[0] = temp_heap.elements[i];
        temp_heap.elements[i] = temp;
        
        // Riduco la dimensione utile dell'heap
        temp_heap.size--;
        
        // Ripristino la struttura sulla radice
        siftDown(&temp_heap, 0);
    }
}

void heapify(Item *arr, int n) {
    struct heap temp_heap;
    temp_heap.elements = arr;
    temp_heap.size = n;
    temp_heap.max_size = n;
    
    // Il primo nodo non foglia si trova a (n - 2) / 2
    for (int i = (n - 2) / 2; i >= 0; i--) {
        siftDown(&temp_heap, i);
    }
}