#include<iostream>
#include<string>


using namespace std;

bool solve(string str){
    bool returnBit = true;

    int n = str.size();
    for(int i = 0; i < n - 1; i++){
        if(str[i] == 'Y' && str[i + 1] == 'Y')
            returnBit = false;
    }
    return returnBit;
}


int main(){

    int t;
    cin>> t;
    string str;

    while(t--){
        cin>> str;
        if(solve(str) == true)
            cout<< "Yes\n";
        else
            cout<< "No\n";
    }

}