#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "plot_gantt_utils.h"


typedef struct
{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} Process;


void round_robin(Process proc[], int n, int quantum,
                 GanttSlot gantt[], int *g) {

    int rem_bt[n];

    for (int i = 0; i < n; i++)
        rem_bt[i] = proc[i].bt;

    int time = 0;
    int completed = 0;

    *g = 0;

    while (completed < n) {

        bool any = false;

        for (int i = 0; i < n; i++) {

            if (rem_bt[i] > 0 && proc[i].at <= time) {

                any = true;

                int start = time;
                int run_for;

                if (rem_bt[i] > quantum) {
                    run_for = quantum;
                    rem_bt[i] -= quantum;
                }
                else {
                    run_for = rem_bt[i];
                    rem_bt[i] = 0;

                    proc[i].ct = time + run_for;
                    proc[i].tat = proc[i].ct - proc[i].at;
                    proc[i].wt = proc[i].tat - proc[i].bt;

                    completed++;
                }

                time += run_for;

                // Store Gantt slot
                sprintf(gantt[*g].name, "P%d", i + 1);
                gantt[*g].start = start;
                gantt[*g].end = time;

                (*g)++;
            }
        }

        if (!any) {
            time++;
        }
    }
}


int main(){
    

    int n;

    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    
    Process proc[n];

    printf("\n\nEnter the AT and the BT for all the processes : \n");
    for(int i = 0; i < n; i++){
        scanf("%d %d", &proc[i].at, &proc[i].bt);
    }

    int q;
    printf("Enter the value of time quantum for the Round Robin algorithm : ");
    scanf("%d", &q);

    int g = 0;
    GanttSlot gantt[100];
    round_robin(proc, n, q, gantt, &g);


    plotGantt(gantt, g);


}
