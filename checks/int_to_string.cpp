#include<iostream>
#include<cmath>

using namespace std;


string int_to_string(int n){
    string return_s = "";
    while(n != 0){
        return_s = ((n % 2 == 1) ? "1": "0")  + return_s;
        n /= 2;
    }
    return return_s;
}

int string_to_int(string s){
    int n = s.size();
    int degree = 0;
    int sum = 0;
    for(int i = n - 1; i >= 0; i--){
        sum += ((s[i] == '1') ? pow(2, degree) : 0);
        degree++;
    }
    return sum;
    }


int power(int b, int exp){
    int result = 1;
    for(int i = 0; i < exp; i++){
        result = (result * b) % 1000000007;
    }
    return result;
}

int main(){
    int x;
    cin>> x;
    cout<< int_to_string(x)<< endl;
    string s;
    cin>> s;
    cout<< string_to_int(s)<< endl;
    cout<< power(x, 3);
}  


