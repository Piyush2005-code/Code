#include<stdio.h>
#include "utils.h"

void merge(int arr[], int l, int r, int m){
    if(l < r){
        int n1 = m + 1 - l;
        int n2 = r - m;

        int left[n1];
        int right[n2];

        for(int i = 0; i < n1; i++){
            left[i] = arr[l + i];
        }
        for(int j = 0; j < n2; j++){
            right[j] = arr[m + 1 + j];
        }
        
        // printing the arrays left and right once to check
        // for(int i = 0; i < n1; i++){
        //     printf("%d ", left[i]);
        // }
        // printf(" || ");

        // for(int j = 0; j < n2; j++){
        //     printf("%d ", right[j]);
        // }
        // printf("\n");


        int i = 0; int j = 0;

        while(i < n1 && j < n2){
            if(left[i] < right[j]){
                arr[l++] = left[i++];
            }
            else{
                arr[l++] = right[j++];
            }
        }

        while(i < n1){
            arr[l++] = left[i++];
        }

        while(j < n2){
            arr[l++] = right[j++];
        }

    }

}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, r, m);
    }
}

int binary_search(int arr[], int target, int n){
    int l = 0, r = n - 1;

    while(l <= r){
        int m = (l + r) / 2;
        if(arr[m] == target){
            return m;
        } else if(arr[m] < target){
            l = m + 1;
        } else{
            r = m - 1;
        }
    }
    return -1;
}

