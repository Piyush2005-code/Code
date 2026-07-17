#include<iostream>


using namespace std;


// The code is only valid for 32-bit signed integers.
int main(){
    int x;
    cin >> x;
    int res = 0;

    for(int i = 0; i < 32; i++){
        res = (res << 1) | (x & 1);
        x >>= 1;
    }
    
    cout << res;
}
