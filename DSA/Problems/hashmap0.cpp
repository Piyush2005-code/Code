#include<iostream>
#include<vector>
#include<map>
#include<string>
#define ull unsigned long long
// using namespace std;

ull PRIME_BASE = 31;
ull PRIME_MOD = 1e9 + 7;

ull compute_hash(std::string str){
    int k = str.length();
    ull hash = 0;
    std::vector<ull> ppowers(k, 1);
    for(int i = 1; i < k; i++) ppowers[i] = ppowers[i - 1] * PRIME_BASE;
    for(int i = 0; i < k; i++) {hash += (str[i] - 'a' + 1) * ppowers[i];}
    return hash;
}

bool check_duplicates(std::string str, int pattern_size){
    int n = str.length();
    for(int i = 0; i <= n - pattern_size + 1; i++){
        for(int j = i + 1; j <= n - pattern_size + 1; j++){
            if(compute_hash(str.substr(i, pattern_size)) == compute_hash(str.substr(j, pattern_size)))
            return true;
        }
    }
    return false;
}

std::string return_duplicate(std::string str, int pattern_size){
    int n = str.length();
    for(int i = 0; i <= n - pattern_size + 1; i++){
        for(int j = i + 1; j <= n - pattern_size + 1; j++){
            if(compute_hash(str.substr(i, pattern_size)) == compute_hash(str.substr(j, pattern_size)))
                return str.substr(i, pattern_size);
        }
    }
    return "";
}

int main(){

    std::string str;
    std::getline(std::cin, str);

    // std::cout<< check_duplicates(str, 3);
    int current_pattern_length = str.length() / 2;
    int n = str.length();

    if(check_duplicates(str, current_pattern_length)){
        while(check_duplicates(str, current_pattern_length) && current_pattern_length < n)
            current_pattern_length++;
        current_pattern_length--;
    } else{
        while(!check_duplicates(str, current_pattern_length) && current_pattern_length > 1)
            current_pattern_length--;
    }

    if(check_duplicates(str, current_pattern_length))
        std::cout<< return_duplicate(str, current_pattern_length);
    else{
        std::cout<< "";
    }



}

