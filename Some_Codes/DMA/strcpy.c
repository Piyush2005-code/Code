#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char** argv){

    if(argc < 2){
        fprintf(stderr, "usage: ./strcpy <example_string>\n");
        return 0;
    }
    else if(argc > 2){
        fprintf(stderr, "usage: ./strcpy <example_string>\nenter only one argument");
        return 0;
    }

    char *src = argv[1];
    printf("The length of string is %lu\n\n", strlen(src));

    // strcpy() requires the dst pointer to have some memory already allocated.
    char *dst = (char*)malloc(strlen(src)); // This should have a strlen(const char*) + 1; for the null_terminating_character.
    strcpy(dst, src);

    // In the case of dup, I am using strdup() that will now handle the case of memory alloation as well while duplication.
    char *dup = strdup(src);

    printf("Printing of both the strings:\n");
    printf("The first string: destination = %s, from the use of strcpy()\n", dst);
    printf("The second string: duplicate = %s, from the use of strdup()\n", dup);
    printf("From here we can see that the strlen() function returns only the number of characters excluding the null terminating character and needs to be passed like strlen(const char*) + 1, in order to actually allocate enough space for the program to work.");
    
}
