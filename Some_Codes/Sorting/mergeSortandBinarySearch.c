#include<stdio.h>
#include<stdlib.h>
#include "utils.h"


int main(){

    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", arr + i);
    }

    mergeSort(arr, 0, n - 1);
    
    printf("The below is the Sorted Array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n\n");

    int target;
    printf("Enter the Target to be found: ");
    scanf("%d", &target);

    int idx = binary_search(arr, target, n);

    if(idx == -1){
        printf("The target is not present in the array!\n");
        return 0;
    }
    printf("The index of the target %d in the array is: %d", target, idx);
    
}


