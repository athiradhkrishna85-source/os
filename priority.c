#include <stdio.h>
#include <string.h>

struct process {
    char pid[10];
    int at, bt, pr;
    int wt, tat, ct;
    int completed;
};

int main() {
    int n, time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;
    struct process p[20];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time, Burst Time and Priority for process %d: ", i + 1);
        scanf("%s %d %d %d", p[i].pid, &p[i].at, &p[i].bt, &p[i].pr);
        p[i].completed = 0;
    }

    while (completed < n) {
        int idx = -1;
        int highest = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].completed == 0) {
                if (p[i].pr > highest) {
                    highest = p[i].pr;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            
            total_wt += p[idx].wt;
            total_tat += p[idx].tat;
            
            p[idx].completed = 1;
            completed++;
        } else {
            time++;
        }
    }

    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].wt);
    }

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].tat);
    }

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
