#include<iostream>


using namespace std;


int main(){

    int a, b;
    cin>> a>> b;


    if((a | b) == a + b - (a & b)) cout<< "Yes it holds.\n";
    else cout<< "No it doesn't.\n";

}