#include<iostream>
#include<string>

using namespace std;

// Virtual Functions:

class Animal{
    public:
        virtual void makeSound(){
            cout<< "\nAnimal Sound.";
        }
};

class Dog: public Animal{
    public:
        void makeSound(){
            cout<< "\nWoof Woof.";
        }
};








int main(){

    Animal* a;
    Dog dog;
    a = &dog;

    a->makeSound(); // with the keyword of virtual, the method of the child class will be used,
    // even if the pointer is of the parent class, otherwise the method of the parent class would,
    // have been used if the pointer of the parent class is used.

}