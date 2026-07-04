#include<iostream>
#include<string>
#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"


using namespace std;


bool checkPalindrome(string s){
    string copy = s;
    reverse(copy.begin(), copy.end());
    return s == copy;
}


int main(int argc, char** argv){
    
    string s;
    cin >> s;

    for(int i = 0; i < argc; i++){
        cout << argv[i] << ": ";
        cout << ((checkPalindrome(argv[i]) ? "The string is a Palindrome\n" : "The string is not a Palindrome\n"));
    }
    // cout << ((checkPalindrome(s)) ? "The string is a Palindrome" : "The string is not a Palindrome");
}


