#include<iostream>

using namespace std;

int main(){

    int n, n_spaces;
    cin>> n;
    
    for(int i = 0; i < n; i++){
        for(int l = 0; l < i; l++) cout<< " ";
        for(int l = 0; l < 2 * (n - i) -1; l++) cout<< "*";
        for(int l = 0; l < i; l++) cout<< " ";
        cout<< endl;
    }


}