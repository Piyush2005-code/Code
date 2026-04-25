#include<iostream>
#include<string>
#include<list>

using namespace std;


class User{
public:
    string name;
    string password;
    int AccountBalance;
    list<string> Courses;
    
    void Current_Status(){
        cout<< "\n\nName : " << name << endl;    
        cout<< "Account Balance : " << AccountBalance << endl;
        cout<< "\nThe Courses "<< name<< " is enrolled in, are : \n";
        for(auto str : Courses){
            cout<< str<< endl;
        }
    }
    
    User(string Name, string Password, int Account_Balance){
        name = Name;
        password = Password;
        AccountBalance = Account_Balance;
        // Taking inputs of the initial number of courses:
        int n;
        cout<< "Enter the number of Initial Courses that you wish to enter:";
        cin>> n;
        for(int i = 0; i < n; i++){
            string courseName;
            cin >> courseName;
            Courses.push_back(courseName);
        }
        
        Current_Status();
    }
};

int main(){
    User D36("Piyush", "password", 1800);
    // User D36;
    // D36.name = "Piyush";
    // D36.password = "D36_Pass";
    // D36.AccountBalance = 1800;
    // D36.Courses = {"AndrewNG_ML_Basics", "DL_Andrew_NG_Basics", "DL_Andrew_NG_Advanced"};

}