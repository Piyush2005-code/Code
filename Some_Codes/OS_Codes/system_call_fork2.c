#include <stdio.h>
#include <unistd.h>



int main() {
    int x = 10;
    pid_t pid = fork();
    if (pid == 0) {
        x += 5;
        printf("Child: x = %d\n", x);
    } else {
        x -= 5;
        printf("Parent: x = %d\n", x);
        printf("I am printing this statement in the else statement so that it is only printed once:\n");
        printf("The parent's and the child's data variables are not in the same shared memory, but they are copied for different processes, but the parent and child heirarchy is maintained for a different purpose: that is to sometimes have the child terminate before the parent process and evict the parent's PCB\n");
    }
    return 0;
}
