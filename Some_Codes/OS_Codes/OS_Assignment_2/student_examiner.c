#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int expected[4] = {1275, 5040, 10, 9876};
    pid_t pid[4];

    for (int i = 0; i < 4; i++) {
        pid[i] = fork();

        if (pid[i] < 0) {
            perror("fork");
            exit(1);
        }

        if (pid[i] == 0) {
            int result = 0;

            if (i == 0) {
                for (int j = 1; j <= 50; j++)
                    result += j;
                printf("Student 1 [PID %d]: Sum = %d -> exit(%d)\n",
                       getpid(), result, result % 256);
            }
            else if (i == 1) {
                result = 1;
                for (int j = 1; j <= 7; j++)
                    result *= j;
                printf("Student 2 [PID %d]: Factorial = %d -> exit(%d)\n",
                       getpid(), result, result % 256);
            }
            else if (i == 2) {
                for (int j = 1; j <= 20; j++) {
                    if (j % 2 == 0)
                        result++;
                }
                printf("Student 3 [PID %d]: Even numbers = %d -> exit(%d)\n",
                       getpid(), result, result % 256);
            }
            else {
                int n = 6789;

                while (n > 0) {
                    result = result * 10 + n % 10;
                    n /= 10;
                }

                printf("Student 4 [PID %d]: Reverse = %d -> exit(%d)\n",
                       getpid(), result, result % 256);
            }

            exit(result % 256);
        }
    }

    int passed = 0;

    for (int i = 0; i < 4; i++) {
        int status;
        waitpid(pid[i], &status, 0);

        int result = WEXITSTATUS(status);

        if (result == expected[i] % 256) {
            printf("Examiner: Student %d -> CORRECT\n", i + 1);
            passed++;
        } else {
            printf("Examiner: Student %d -> WRONG\n", i + 1);
        }
    }

    printf("Examiner Report: %d/4 students passed.\n", passed);

    return 0;
}
