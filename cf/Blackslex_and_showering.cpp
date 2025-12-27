#include<iostream>
#include<vector>

using namespace std;

int abs(int a, int b){
    return (a > b)? (a - b): (b - a);
}

int main(){
    int t;
    cin>> t;

    while(t--){
        int n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>> arr[i];
        }
        int min = 999;
        for(int i = 0; i < n; i++){
            int abs_sum = 0;
            for(int j = 0, k = 1; j < n, k < n; j++, k++){
                if(j == i){j++; k++;}
                if(k == i && k < n - 1){
                    k++;
                    abs_sum += abs(arr[j], arr[k]);
                    if(k < n - 1){j = k; k++;}
                    else break;
                }
                abs_sum += abs(arr[j], arr[k]);
            }
            if(abs_sum < min) min = abs_sum;
        }
        cout<< min;
    }

}