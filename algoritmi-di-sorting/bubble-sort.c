#include "../utils.h"


void bubble_sort(int arr[], int n){
    for(int i = 1; i < n; i ++){
        for(int j = 0; j < n - i; i++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubble_sort_adaptive(int arr[], int n){
    int ordinato = 0;
    for(int i = 0; i < n && !ordinato; i++){
        ordinato = 1;
        for(int j = 0; j < n - i; j++){
            if(arr[j] < arr[j+1]){
                swap(&arr[j], &arr[j + 1]);
                ordinato = 0;
            }
        }
    }
}