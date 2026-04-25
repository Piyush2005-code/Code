#include<iostream>
#include<list>
#include<string>

using namespace std;

int main(){

    list<string> l1 = {"Piyush", "Pragyan", "Jaenil", "Ridham", "Darsh"};

    l1.push_front("Aarush");
    l1.push_back("Akshita");
    l1.push_back("Tanisha");

    for(string str: l1){
        cout<< str<< " ";
    }

    cout<< endl;

    list<string>::iterator it = l1.begin();

    for(int i = 0; i < l1.size(); i++){
        cout<< *it<< " ";
        advance(it, 1);
    }

    cout<< endl;

    advance(it, -3);

    cout<< *it;


}

