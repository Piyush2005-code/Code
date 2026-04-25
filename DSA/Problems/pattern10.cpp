#include<iostream>

using namespace std;

void printPattern10(int target, int traversal);

void printPattern10(int target, int traversal){
    if(traversal == target){
        for(int i = 0; i < target; i++) cout<< "*";
        cout<< endl;
    }
    else{
        for(int i = 0; i < traversal; i++) cout<< "*";
        cout<< endl;
        printPattern10(target, traversal + 1);
        for(int i = 0; i < traversal; i++) cout<< "*";
        cout<< endl;
    }
}

int main(){
    int n; cin>> n;
    printPattern10(n, 1);
}