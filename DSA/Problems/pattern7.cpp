#include<iostream>


using namespace std;


int main(){
    int n;
    cin>> n;
    int n_spaces;
    for(int i = 0; i < n; i++){
        n_spaces = n - i - 1;
        for(int l = 0; l < n_spaces; l++) cout<< " ";
        for(int l = 0; l < 2 * i + 1; l++) cout<< "*";
        for(int l = 0; l < n_spaces; l++) cout<< " ";
        cout<< endl;
    }


}