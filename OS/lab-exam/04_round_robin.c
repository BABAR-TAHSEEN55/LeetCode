#include <stdio.h>

int main() {
  int n, i, time = 0, completed = 0, quantum, progress;
  int pid[20], at[20], bt[20], rem[20], ct[20], tat[20], wt[20];
  float avg_tat = 0.0f, avg_wt = 0.0f;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    pid[i] = i + 1;
    printf("Enter arrival time and burst time for P%d: ", pid[i]);
    scanf("%d%d", &at[i], &bt[i]);
    rem[i] = bt[i];
    ct[i] = 0;
  }

  printf("Enter time quantum: ");
  scanf("%d", &quantum);

  while (completed < n) {
    progress = 0;

    for (i = 0; i < n; i++) {
      if (at[i] <= time && rem[i] > 0) {
        progress = 1;
        if (rem[i] > quantum) {
          time += quantum;
          rem[i] -= quantum;
        } else {
          time += rem[i];
          rem[i] = 0;
          ct[i] = time;
          completed++;
        }
      }
    }

    if (!progress) {
      time++;
    }
  }

  printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
  for (i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    avg_tat += tat[i];
    avg_wt += wt[i];
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i],
           wt[i]);
  }

  printf("Average Turnaround Time = %.2f\n", avg_tat / n);
  printf("Average Waiting Time = %.2f\n", avg_wt / n);
  return 0;
}
