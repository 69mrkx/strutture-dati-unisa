#include <stdio.h>
#include <stdlib.h>
#include "item/item.h"   // Assicurati che contenga la definizione di Item e le funzioni di output
#include "heap/heap.h"
#include "Btree/Btree.h"

int main() {
    
    Heap h = createHeap(); 

    printf("--- Test Inserimento Heap ---\n");
    int valori[] = {15, 10, 20, 5, 30, 25};
    int n = 6;

    for (int i = 0; i < n; i++) {
        Item item = newItem(valori[i]);
        printf("Inserisco: %d\n", valori[i]);
        insertHeap(h, item);
    }

    printf("\n--- Test Estrazione (Dovrebbe stampare in ordine decrescente) ---\n");
    while (getSizeHeap(h) > 0) {
        Item max = extractMax(h);
        printf("Estratto: %d\n", getItemValue(max)); // Assicurati di avere una funzione per leggere l'int dall'item
    }

    // Pulizia
    free(h);
    printf("\nTest completato.\n");

    return 0;
}