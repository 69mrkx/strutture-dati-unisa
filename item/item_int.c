
#include "item.h"
#include <stdio.h>
#include <stdlib.h>


Item inputItem(void){
    int n;
    printf("Valore: ");
    scanf("%d", &n);
    return (Item)(long)n;
}
void outputItem(Item it){
    int *value = (int *)it;
    printf("%d", (int)(long)value);
}
int compareItem(Item it1, Item it2){
    // Ritorna: 0 se uguali, <0 se it1 < it2, >0 se it1 > it2
    int *value1 = (int *)it1;
    int *value2 = (int *)it2;
    return *value1 - *value2;
} 
Item cloneItem(Item it){
    // Effettua la copia profonda dell'oggetto
    int *value = (int *)it;
    int n = *value;

    return (Item)(long)n;
}
void freeItem(Item it){
}