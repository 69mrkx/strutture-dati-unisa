#include <stdlib.h>
#include "../item/item.h"
#include "heap.h"   // Assicurati di aggiornare l'header di conseguenza
#include "../Btree/Btree.h"  // La tua struttura alberi
#include "../utils.h"

// Nuova struttura Heap basata su albero
struct heap {
    Btree root;
    int size;
};

int getSizeHeap(Heap h){
    return h->size;
}

Heap createHeap() {
    Heap h = malloc(sizeof(struct heap));
    h->root = newBtree();
    h->size = 0; // Aggiungi max_size alla struct heap
    return h;
}

void siftUp(Heap h, int i) {
    // Risaliamo verso l'alto. Avendo perso l'accesso O(1), ci mettiamo O(log N) a trovare
    // i nodi, portando la complessità totale a O(log^2 N), accettabile per gli alberi.
    while (i > 0) {
        int p = (i - 1) / 2; // Indice del padre
        
        Btree node_i = getNodeByIndex(h->root, i);
        Btree node_p = getNodeByIndex(h->root, p);
        
        if (compareItem(getBtreeRoot(node_i), getBtreeRoot(node_p)) > 0) {
            // Scambio figlio e padre (scambiamo solo i valori, non i nodi)
            swap(getBtreeRoot(node_i), getBtreeRoot(node_p));

            i = p; // Continuo dal padre
        } else {
            break; // Proprietà rispettata
        }
    }
}

void siftDown(Heap h, int i) {
    Btree curr = getNodeByIndex(h->root, i);
    
    while (curr != NULL) {
        Btree left = getLeft(curr);
        Btree right = getRight(curr);
        Btree max_node = curr;
        
        Item val_max = getBtreeRoot(max_node);
        
        // Trova il maggiore tra il nodo corrente e i figli
        if (left != NULL) {
            Item val_left = getBtreeRoot(left);
            if (compareItem(val_left, val_max) > 0) {
                max_node = left;
                val_max = val_left;
            }
        }
        
        if (right != NULL) {
            Item val_right = getBtreeRoot(right);
            if (compareItem(val_right, val_max) > 0) {
                max_node = right;
                val_max = val_right;
            }
        }
        
        if (max_node != curr) {
            // Scambio dei valori usando getter e setter
            Item temp = getBtreeRoot(curr);
            setBtreeRoot(curr, val_max);
            setBtreeRoot(max_node, temp);
            
            curr = max_node; // Continuo la discesa
        } else {
            break; // Proprietà rispettata
        }
    }
}

int insertHeap(Heap h, Item e) {
    // Se l'albero è vuoto, creiamo la radice
    if (h->size == 0) {
        h->root = buildBtree(newBtree(), newBtree(), e);
        h->size++;
        return 1;
    }
    
    // Troviamo il padre dove inserire la nuova foglia
    int parent_idx = (h->size - 1) / 2;
    Btree parent = getNodeByIndex(h->root, parent_idx);
    Btree new_node = buildBtree(newBtree(), newBtree(), e);
    
    // Lo agganciamo a sinistra (se dispari) o a destra (se pari)
    // Utilizziamo le funzioni setter invece dell'accesso diretto
    if (h->size % 2 != 0) {
        setLeft(parent, new_node); 
    } else {
        setRight(parent, new_node);
    }
    
    h->size++;
    siftUp(h, h->size - 1); // Ripristino
    return 1;
}

Item extractMax(Heap h) {
    if (h->size == 0 || isEmptyBtree(h->root)) {
        return NULL; // Coda vuota
    }
    
    // 1. Usiamo la tua funzione per leggere la radice
    Item max_val = getBtreeRoot(h->root);
    
    // Caso in cui rimane solo un elemento
    if (h->size == 1) {
        free(h->root); // Nota: free su tipo opaco potrebbe richiedere una funzione dedicata (es. freeBtree)
        h->root = newBtree();
        h->size = 0;
        return max_val;
    }
    
    // Troviamo l'ultimo nodo e il suo padre
    int last_idx = h->size - 1;
    int parent_idx = (last_idx - 1) / 2;
    Btree last_node = getNodeByIndex(h->root, last_idx);
    Btree parent = getNodeByIndex(h->root, parent_idx);
    
    // 2. Spostiamo il valore dell'ultimo nodo in radice
    // Poiché la struct è opaca, serve una funzione per SETTARE il valore
    setBtreeRoot(h->root, getBtreeRoot(last_node));
    
    // 3. Stacchiamo l'ultimo nodo dall'albero
    // Anche qui, servono funzioni setter per aggiornare i figli
    if (last_idx % 2 != 0) {
        setLeft(parent, newBtree());
    } else {
        setRight(parent, newBtree());
    }
    
    free(last_node); // Liberiamo la memoria
    h->size--;
    
    // Ripristiniamo la proprietà dall'alto
    siftDown(h, 0); 
    
    return max_val;
}

// Per gli alberi dinamici, l'heapify su un array pre-esistente
// viene tipicamente sostituito da N inserimenti sequenziali.
void heapify_tree(Heap h, Item *arr, int n) {
    for (int i = 0; i < n; i++) {
        insertHeap(h, arr[i]);
    }
}

void heapsort(Item *arr, int n) {
    // 1. Creiamo un nuovo Heap vuoto
    struct heap h;
    h.root = newBtree();
    h.size = 0;
    
    // 2. Costruiamo l'heap inserendo gli elementi (heapify)
    heapify_tree(&h, arr, n);
    
    // 3. Estraiamo il massimo uno per uno partendo dalla fine dell'array
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = extractMax(&h);
    }
}