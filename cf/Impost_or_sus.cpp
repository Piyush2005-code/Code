#include<iostream>
#include<string>

using namespace std;

int solve(string& str){
    int n = str.size();
    int count = 0;
    if(str[0] == 'u'){
        str[0] = 's'; count++;
    }
    if(str[n - 1] == 'u'){
        str[n - 1] = 's'; count++;
    }
    int i = 0;
    while(i < n - 2){
        while(str[i] != 'u' && i < n - 2){
            i++;
            if(str[i] == 'u'){
                i--; break;
            }
            if(i == n - 2){
                i--; break;
            }
        }
        if(str[i + 2] == 's'){
            i += 2; continue;
        }
        else{
            str[i + 2] = 's'; count++; continue;
        }
    }
    return count;
}

int main(){

    int t;
    cin >> t;
    string s;
    while(t--){
        cin>> s;
        cout<< solve(s)<< endl;
    }

}