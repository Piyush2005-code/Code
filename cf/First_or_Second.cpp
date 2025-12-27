#include<iostream>
#include<string>


using namespace std;

int solve(vector<long long> a){
    int n = a.size(); long long X = 0;
    int i = 0, j = 1;

    while(i < n && j < n){
        if(X + a[i] > X - a[j]){
            X += a[i];
            i = j; j++;
        }
        else{
            X -= a[j];
            j++;
        }
    }

    return X;
}

int main(){
    int t;
    cin>> t;
    int n;
    while(t--){
        cin>> n;
        vector<long long> arr(n);
        for(int i = 0; i < n; i++){
            cin>> arr[i];
        }
        cout<< solve(arr)<< endl;
    }

}