#include<iostream>
#include<vector>
#include<list>
#include<chrono>
#include<algorithm>


using namespace std;

int main(){
//Callable Functions
auto f = []() -> int {return rand() % 10000;};

vector<int> values(10000);

generate(values.begin(), values.end(), f);
//measuring execution time of sorting
auto start = chrono::high_resolution_clock::now();
sort(values.begin(), values.end());
auto end = chrono::high_resolution_clock::now();

auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

for(int ele: values){
    cout<< ele<< " ";
}
cout<< endl;

cout<< duration.count()<< endl;


}