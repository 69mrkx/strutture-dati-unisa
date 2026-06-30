#include "../utils.h"
void selection_sort(int arr[], int n){
    for(int i = 0; i < (n-1); i++){
        int min = minimo(&arr[i], n-i) + i;
        swap(&arr[i], &arr[min]);
    }
}