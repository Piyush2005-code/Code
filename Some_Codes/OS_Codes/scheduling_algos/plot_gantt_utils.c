#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"plot_gantt_utils.h"


void plotGantt(GanttSlot gantt[], int g) {

    printf("\nGantt Chart:\n");

    // Process names
    printf("|");
    for (int i = 0; i < g; i++) {
        printf(" %s |", gantt[i].name);
    }

    printf("\n");

    // Start time
    printf("%d", gantt[0].start);

    // End times
    for (int i = 0; i < g; i++) {
        printf("    %d", gantt[i].end);
    }

    printf("\n");
}
