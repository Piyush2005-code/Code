#include<stdio.h>

void func(int *a);

void func(int *a){
    *a = 2;
}

int main(){

    int a = 5;

    func(&a);

    printf("%d", a);

}