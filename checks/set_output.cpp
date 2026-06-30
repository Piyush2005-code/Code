#include<iostream>
#include<vector>
#include<unordered_set>



using namespace std;


int main(){
    unordered_set<char> s;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        s.insert(c);
    }
    
    for(char c : s){
        cout << c << " ";
    }

}


