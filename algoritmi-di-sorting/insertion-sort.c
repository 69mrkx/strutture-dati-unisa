#include "../utils.h"


void insertion_sort(int arr[], int n){
    int i, j, val;
    for(i = 1; i < n; i++){
        val = arr[i];
        j = i - 1;
    }
    // Sposta gli elementi maggiori di val a destra di una posizione

    while(j >= 0 && arr[j] > val){
        arr[j + 1] = arr[j];
        j--; 
    }
    arr[j + 1] = val; // Inserisce val nella posizione libera
}
