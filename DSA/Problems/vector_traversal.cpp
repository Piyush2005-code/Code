#include<iostream>
#include<vector>


using namespace std;


int main(){


    vector<int> arr(10); //vector<int> arr(size, initialized element value);

    arr[0] = 90; arr[1] = 80; arr[2] = 70; arr[3] = 60; arr[4] = 50;
    arr.push_back(7);
    for(auto x: arr){
        cout<< x<< " ";
    }


}