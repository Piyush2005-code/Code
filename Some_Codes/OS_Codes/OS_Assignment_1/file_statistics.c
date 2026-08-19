#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h>
#include <string.h>

void sigint_handler(int sig)
{
    printf("\nInterrupted\n");
    exit(1);
}

void stats(char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd < 0) {
        perror(filename);
        exit(1);
    }

    char buffer[1024];
    int n;

    int characters = 0;
    int lines = 0;
    int words = 0;
    int freq[26] = {0};

    int in_word = 0;

    while ((n = read(fd, buffer, sizeof(buffer))) > 0) {

        for (int i = 0; i < n; i++) {

            char ch = buffer[i];

            characters++;

            if (ch == '\n')
                lines++;

            if (isalpha(ch)) {
                ch = tolower(ch);
                freq[ch - 'a']++;
            }

            if (isspace(ch)) {
                in_word = 0;
            }
            else if (in_word == 0) {
                words++;
                in_word = 1;
            }
        }
    }

    close(fd);

    char output_name[100];
    sprintf(output_name, "stats_%s.txt", filename);

    int out = open(output_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (out < 0) {
        perror(output_name);
        exit(1);
    }

    char str[100];

    sprintf(str, "Characters: %d\n", characters);
    write(out, str, strlen(str));

    sprintf(str, "Lines: %d\n", lines);
    write(out, str, strlen(str));

    sprintf(str, "Words: %d\n", words);
    write(out, str, strlen(str));

    for (int i = 0; i < 26; i++) {
        sprintf(str, "%c: %d\n", 'a' + i, freq[i]);
        write(out, str, strlen(str));
    }

    close(out);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Enter file names\n");
        return 1;
    }

    signal(SIGINT, sigint_handler);

    for (int i = 1; i < argc; i++) {

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
        }
        else if (pid == 0) {
            stats(argv[i]);
            exit(0);
        }
    }

    for (int i = 1; i < argc; i++)
        wait(NULL);

    int summary = open("summary_report.txt",
                       O_WRONLY | O_CREAT | O_TRUNC,
                       0644);

    if (summary < 0) {
        perror("summary_report.txt");
        return 1;
    }

    char buffer[1024];

    for (int i = 1; i < argc; i++) {

        char filename[100];
        sprintf(filename, "stats_%s.txt", argv[i]);

        int fd = open(filename, O_RDONLY);

        if (fd < 0)
            continue;

        int n;

        while ((n = read(fd, buffer, sizeof(buffer))) > 0)
            write(summary, buffer, n);

        close(fd);
    }

    close(summary);

    return 0;
}
