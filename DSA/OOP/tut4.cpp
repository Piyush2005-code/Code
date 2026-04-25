#include<iostream>
#include<string>

using namespace std;


class animal{
    public:
        virtual void makeSound(){
            cout<< "Wee wee\n";
        }
};

class dog : public animal{
    public:
        void makeSound() override{
            cout<< "Woof woof!!\n";
        }
};

class pig : public animal{
    public:
        void makeSound() override{
            cout<< "Snort snort\n";
        }
};


int main(){

    animal my_animal;
    dog my_dog;
    pig my_pig;

    my_animal.makeSound();
    my_dog.makeSound();
    my_pig.makeSound();

}