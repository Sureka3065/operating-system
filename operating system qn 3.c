#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

typedef struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

void swap(Process *xp, Process *yp) {
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_by_burst_time(Process processes[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (processes[j].burst_time > processes[j+1].burst_time) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

void calculate_completion_time(Process processes[], int n) {
    int i;
    int current_time = 0;
    for (i = 0; i < n; i++) {
        current_time += processes[i].burst_time;
        processes[i].completion_time = current_time;
    }
}

void calculate_turnaround_time(Process processes[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
}

void calculate_waiting_time(Process processes[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void print_results(Process processes[], int n) {
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    int i;
    printf("Process\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].pid, 
               processes[i].burst_time, 
               processes[i].arrival_time,
               processes[i].completion_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n = 4; 
    Process processes[MAX_PROCESS] = {
        {1, 6, 0, 0, 0, 0},
        {2, 8, 0, 0, 0, 0},
        {3, 7, 0, 0, 0, 0},
        {4, 3, 0, 0, 0, 0}
    };
    
   
    sort_by_burst_time(processes, n);
    
   
    int i;
    for(i=0;i<n;i++) 
	{
        processes[i].arrival_time = 0;
    }


    
