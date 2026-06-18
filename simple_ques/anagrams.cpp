#include <iostream>
#include <string>


using namespace std;


bool are_anagrams(string str1, string str2){
    if(str1.size() != str2.size()) return false;

    int freq1[26] = {0};
    int freq2[26] = {0};

    for(int i = 0 ; i < str1.size() ; i++){
        freq1[str1[i] - 'a']++;
        freq2[str2[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(freq1[i] != freq2[i]) return false;
    }
    return true;
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    
    cout << are_anagrams(str1, str2);

}
