
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int minimo(int *arr, int n){
    int min = 0;
    for(int i = 1; i < n; i++){
        if (arr[min] > arr[i]) min = i;
    }

    return min;
}
