//This Code has been created in order to check whether the strlen() function gives the correct output if it is applied on a single row of a char 2D Array.

#include<stdio.h>
#include<string.h>

int main(){


    char set_of_strings[10][20];

    scanf("%s", set_of_strings[1]);

    printf("%s %lu", set_of_strings[1], strlen(set_of_strings[1]));
}

