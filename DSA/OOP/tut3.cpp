#include<iostream>
#include<string>
#include<chrono>
#include<thread>

using namespace std;
using namespace std::this_thread; // sleep_for(); ,sleep_until(system_clock() + 10ns);
using namespace std::chrono_literals;
using std::chrono::system_clock;

class Dog{
    protected:
        string Vocal_sound;
        int age;
        string name;

    public:
        Dog() : Vocal_sound("Woof!!"), age(0) {
            congratulate("Born");
            name_puppy();
            make_sound();
        }
            
            void congratulate(string event){
            if(event == "Born") cout<< "\nCongratulations!! A puppy is born";
            if(event == "Walk") cout<< "\nCongratulations!! "<< name<< " has taken his first steps.";
            if(event == "Spoke") cout<< "\nCongratulations!! "<< name<< " has "<< Vocal_sound<< "-ed for the first time.";
            if(event == "Eating") cout<< "\nCongratulations!! "<< name<< " is now eating its food";
        }
        void name_puppy(){
            string Name;
            cout<< "\nEnter the name of the puppy: ";
            cin>> Name;
            name = Name;
            cout<< "\nFrom now onwards, the name of the puppy is "<< name<< ".";
        }

        void make_sound(){
            cout<< "\nDog: "<< Vocal_sound<< " "<< Vocal_sound<< "!!";
        }

        void age_by(int step = 1){
            age += step;
        }

        void getAge(){
            cout<< "\nAge: "<< age;
        }

        void getName(){
            cout<< "\nName: "<< name;
        }

        void getInfo(){
            cout<< "\n*--Info--*";
            getName();
            getAge();
            cout<< "\n*--------*";
        }

        friend void tame(Dog& dog);
};

void tame(Dog& dog){
    cout<< endl<< dog.name<< ", good dog"<< "\nTaming";
    for(int i = 0; i < 3; i++){
        cout<< ".";
        sleep_for(1s);
    }
    sleep_until(system_clock::now() + 2s);
    cout<< "\nDog Tamed!!";
}


// You learned from the Access Specifiers chapter that there are three specifiers available in C++.

// Until now, we have only used public (members of a class are accessible from outside the class) and private (members can only be accessed within the class).

// The third specifier, protected, is similar to private, but it can also be accessed in the inherited class

int main(){

    Dog puppy;
    puppy.getInfo();
    puppy.congratulate("Walk");
    tame(puppy);

    
}
