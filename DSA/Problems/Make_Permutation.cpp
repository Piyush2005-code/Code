#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int sol(){
    int n;
    cin>> n;
    vector<int> numsA(n);
    vector<int> numsB(n);
    vector<int> numsC(n);
    for(int &x : numsA){
        cin>> x;
    }
    sort(numsA.begin(), numsA.end());

    for(int i = 0; i < n; i++)
        numsC[i] = i + 1;

    for(int i = 0; i < n; i++)
        numsB[i] = numsC[i] - numsA[i];

    for(int i = 0; i < n; i++)
        if(numsB[i] < 0)
            return 0;

    return 1;
}

int main(){
    int t;
    cin>> t;

    while(t--){
        if(sol())
            cout<< "YES";
        else
            cout<< "NO";
    }


}

