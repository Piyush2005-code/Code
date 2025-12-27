#include<iostream>
#include<cmath>
#include<string>

using namespace std;

double Loss(vector<vector<string>>){


}


int main(){

    int n;
    cin>> n;

    vector<vector<string>> t(n);
    vector<vector<bool>> L_arr(n);

    for(int i = 0; i < n; i++){
        int size; cin>> size;
        vector<string> t_i(size);
        for(int j = 0; j < size; j++){
            cin>> t_i[j];
        }
        t[i] = t_i;
        vector<bool> L_i(size);
        for(int j = 0; j < size; j++){
            char ch;
            cin>> ch;
            if(ch == 'U') L_i[j] = false;
            if(ch == 'L') L_i[j] = true;
        }
        L_arr[i] = L_i;
    }

    

}