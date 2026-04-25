#include<stdio.h>
#include<stdlib.h>


typedef struct{
    float Real_Part;
    float Imag_Part;
}Complex;


int main(){

    Complex z1;
    Complex z2;

    printf("Enter the first compplex number = ");
    scanf("%f + j%f", &z1.Real_Part, &z1.Imag_Part);
    
    //This was the point of this program to prove that the below statement is Valid
    //And assigns every member of the structure type variable z1 to z2 individually.
    z2 = z1;


    // free(&z1); -----> Not a Valid Statement because the input Argument passed
    // through the free() function is a pointer type variable whichis malloced.
    
    
    printf("\n%.2f + j%.2f", z2.Real_Part, z2.Imag_Part);
    printf("\n%.2f + j%.2f", z2.Real_Part, z2.Imag_Part);

    


}