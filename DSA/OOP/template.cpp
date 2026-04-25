#include<iostream>
#include<string>

using namespace std;


template <typename T1>
T1 add(T1 a, T1 b){
    return a + b;
}

template <typename T1>
class Vector{
    T1 arr;

};




int main(){
    
    cout<< add<int>(1, 2)<< endl;
    cout<< add<string>("Hello", add<string>(" ", "World"))<< endl;
    cout<< add<double> (2.6, 8.9)<< endl;

}



