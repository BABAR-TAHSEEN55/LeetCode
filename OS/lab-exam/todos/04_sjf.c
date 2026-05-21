#include <limits.h>
#include <stdio.h>

int main() {
  int n, i, time = 0, completed = 0, index;
  int pid[20], at[20], bt[20], ct[20], tat[20], wt[20], done[20] = {0};
  float avg_tat = 0.0f, avg_wt = 0.0f;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    pid[i] = i + 1;
    printf("Enter arrival time and burst time for P%d: ", pid[i]);
    scanf("%d%d", &at[i], &bt[i]);
  }

  while (completed < n) {
    int min_bt = INT_MAX;
    index = -1;

    for (i = 0; i < n; i++) {
      if (!done[i] && at[i] <= time && bt[i] < min_bt) {
        min_bt = bt[i];
        index = i;
      }
    }

    if (index == -1) {
      time++;
      continue;
    }

    time += bt[index];
    ct[index] = time;
    tat[index] = ct[index] - at[index];
    wt[index] = tat[index] - bt[index];
    done[index] = 1;
    completed++;
    avg_tat += tat[index];
    avg_wt += wt[index];
  }

  printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
  for (i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i],
           wt[i]);
  }

  printf("Average Turnaround Time = %.2f\n", avg_tat / n);
  printf("Average Waiting Time = %.2f\n", avg_wt / n);
  return 0;
}
