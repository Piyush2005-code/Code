#ifndef PLOT_GANTT_UTILS_H
#define PLOT_GANTT_UTILS_H


typedef struct {
    char name[4];
    int start, end;
} GanttSlot;


void plotGantt(GanttSlot gantt[], int g);


#endif
