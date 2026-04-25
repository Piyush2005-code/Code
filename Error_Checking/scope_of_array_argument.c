/* 
In this part of the error checking, I am now checking if the changes made in an array passed through
a function as an argument is local to that function or is the array changed globally
*/

#include<stdio.h>

void array_reversal(int arr[], int N);

void array_reversal(int arr[], int N){


    for(int i = 0; i < N/2; i++){
        int temp = arr[i];
        arr[i] = arr[N-i-1];
        arr[N-1-i] = temp;
    }


}






int main(){

    int N;
    scanf("%d", &N);
    int Arr[N];

    for(int i = 0; i < N; i++)
        scanf("%d", Arr + i);

    array_reversal(Arr, N);
    
    for(int i = 0; i < N; i++)
        printf("%d ", *(Arr + i));



}