#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_CHAR_SIZE 256


// This file should take care of the statistics and reports of individual files;
// Btw this particular implementation is the scratch implementation of wc command although otherwise it should be pretty easy with the execvp call and wc command.
int stats(char* arg){
    FILE* fp = fopen(arg, "r");
    
    if(fp == NULL){
        printf("\nunable to open the file %s", arg);
        return -1;
    }
    char ch;
    int lc = 0;
    int wc = 1;
    int line_count = 0;
    int freq[MAX_CHAR_SIZE];
    for(int i = 0; i < MAX_CHAR_SIZE; i++) freq[i] = 0;
    bool in_word = false;
    while(((ch = fgetc(fp)) != EOF)){
        freq[ch]++;
        lc += 1;
        if(ch == '\n') {
            line_count += 1;
        }

        if(isspace(ch)){
            in_word = false;
        } else if(!in_word){
            in_word = true;
            wc++;
        }
    }

    fclose(fp);
    char stats_filename[50] = "stats_";
    strcat(stats_filename, arg);
    FILE* fp_write = fopen(stats_filename, "w");
    if(fp_write == NULL){
        printf("\nunable to write to file %s", stats_filename);
    }

    fprintf(fp_write, "Character Count = %d\nLine Count = %d\nWord Count = %d\n", lc, line_count, wc);
    fprintf(fp_write, "\nThe frequency table is given below : \n");
    for(int i = 0; i < MAX_CHAR_SIZE; i++){
        fprintf(fp_write, "%c = %d\n", i, freq[i]);
    }
    fclose(fp_write);
    return 0;
}



int main(int argc, char *argv[]){

    // This is the simple for loop implementation.
    // for(int i = 1; i < argc; i++){
    //     if(stats(argv[i]) == -1){
    //         printf("\nstats did not execute on %s", argv[i]);
    //     }
    // }

    char ch;
    FILE* fp = fopen("summary_report.txt", "w");
    if(fp == NULL) printf("\nThe file for summary cannot be created.");


    fprintf(fp, "The summary for all the files are as follows : \n\n");

    for(int i = 1; i < argc; i++){

        pid_t pid = fork();
        char stats_name[50] = "stats_";

        if(pid < 0){
            printf("\nThe child fork for the argument %s was unsuccessful\n", argv[i]);
        } else if(pid == 0){
            if(stats(argv[i]) == -1){
                printf("\nstats for file %s did not get created, error occurred", argv[i]);
            }
            strcat(stats_name, argv[i]);
            FILE *fp_arg = fopen(stats_name, "r");
            if(fp_arg == NULL){
                printf("\nThe stats file for %s cannot be read after being compiled", argv[i]);
                continue;
            }
            fprintf(fp, "The stats for file %s are : \n\n", argv[i]);
            while(((ch = fgetc(fp_arg)) != EOF)){fputc(ch, fp);}
            fclose(fp_arg);
        }
    }
    
    fclose(fp);
}
