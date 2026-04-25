#include<iostream>
#include<map>
#include<vector>

// Is not running.

using namespace std;

void modify(vector<int> &arr);

void modify(vector<int> &arr){
    int n = arr.size();
    for(int &x: arr){
        x = 2;
        cout<< x<< " ";
    }
    cout<< endl<< endl;
    for(int &x: arr){
        cout<< x<< " ";
    }
    cout<< endl<< endl;

}

int main(){


    int n; cin>> n;
    vector<int> arr(n, 1);
    modify(arr);
    for(int x: arr) cout<< x<< " ";

}