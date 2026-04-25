#include<iostream>

using namespace std;

int main(){

    int a = 5;
    int* pointer; /*Wild Pointer: Uninitialized Pointer, having a random memory address*/

    if(pointer == NULL){
        cout<<"The Pointers are declared with a NULL value.\n";
    }
    pointer = &a;
    cout<<"The value of a is " << *pointer << endl;

}

// Output: The value of a is 5
// Means the pointers are usually not declared with a null value.