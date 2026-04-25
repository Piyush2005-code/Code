#include<iostream>
#include<ctime>


using namespace std;

int *returnRandomArray(int cap);

int *returnRandomArray(int cap){

    static int RanArr[10];
  
    for(int i = 0; i < 10; i++)
        RanArr[i] = rand() % (cap + 1); 

    return RanArr;
}


int main(){

    int cap;
    // cout<< "Enter the size of the random array : "; cin>> size;
    // When I tried for putting an additional 'int size' argument, the error occured during the declaration
    // of static int RanArr[size]: variable length array declaration cannot have 'static' storage duration.
    cout<< "Enter the upper cap of the array elements : "; cin>> cap;

    int * RanArray = returnRandomArray(cap);

    for(int i = 0; i < 10; i++)
        cout<< "*(RanArray + "<< i<< ") : "<< *(RanArray + i)<< "\n";


}