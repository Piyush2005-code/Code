#include<stdio.h>


int main(int argc, char* argv[]){
    int n = argc;
    int i = 0;
    while (i < n){
        printf("%s\n", argv[i]); i++;
    }

}