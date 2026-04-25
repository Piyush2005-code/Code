#include<iostream>
#include<string>
#include<fstream>

using namespace std;


int main(){

    string Line;

    ifstream file("Some_file.txt");

    ofstream fileout("Some_file_output.txt");

    while(getline(file, Line)){
        cout<< Line<< endl;
    }


}
