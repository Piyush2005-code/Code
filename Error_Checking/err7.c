#include<stdio.h>

void sort(int *a,int *b, int *c);

void sort(int *a,int *b, int *c){
    int temp;

    if(*a > *b){
        temp = *a;
        *a = *b;
        *b = temp;
    }

    if(*a > *c){
        temp = *a;
        *a = *c;
        *c = temp;
    }

    if(*b > *c){
        temp = *a;
        *a = *c;
        *c = temp;
    }

}

int main(){

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    sort(&a, &b, &c);

    if(a + b > c){
        if(a==b && b==c)
            printf("Forms equi angled triangle");
        else if(a*a + b*b == c*c)
            printf("Forms right angled triangle");
        else if(a*a + b*b > c*c)
            printf("Forms acute angled traingle");
        else
            printf("Forms obtuse angled triangle");

    }
    else
        printf("Can't form a triangle");


}