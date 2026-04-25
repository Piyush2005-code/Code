#include<iostream>

using namespace std;

int main(){

    char* str = "Piyush";

    for(int i = 0; i < 8; i++)
        cout << *(str + i);

    char a = 81;
    cout << "\n" << a;



}