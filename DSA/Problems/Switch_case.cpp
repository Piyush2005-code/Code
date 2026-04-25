#include<iostream>

using namespace std;


int main(){

    int number;
    cin >> number;
    // Switch case  statements starts their execution on the first 'case' that they encounter as 'True'
    // and executes all the 'cases' till the control flow encounters the first 'break;'.
    switch(number){
        case 1:
            cout<< "It's Monday\n";
            break;
        case 2:
            cout<< "It's Tuesday\n";
            break;
        case 3:
            cout<< "It's Wednesday\n";
            break;
        case 4:
            cout<< "It's Thursday\n";
        case 5:
            cout<< "It's Friday\n";
            // break;
        case 6:
            cout<< "It's Saturday\n";
            break;
        case 7:
            cout<< "It's Sunday\n";
            // break;
        default:cout<< "Well we are in default.\n";
    }



}