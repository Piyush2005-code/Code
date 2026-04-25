#include<iostream>

using namespace std;

double dot_product(double* x1, double* x2, int l, int r);

double dot_product(double* x1, double* x2, int l, int r){
    if(l==r){
        return (*(x1 + l)) * (*(x2 + l));
    }
    else{
        int m = (r - l + 1)/2;
        return dot_product(x1, x2, l, m) + dot_product(x1, x2, m + 1, r);
    }

}

double dot(double x1[], double x2[]);

double dot(double x1[], double x2[]){
    return sizeof(x1)/ sizeof(x1[0]);
}

int main(){

    double x1[3] = {1.0, 2.0, 3.0};
    
    dot(x1, x1);

}