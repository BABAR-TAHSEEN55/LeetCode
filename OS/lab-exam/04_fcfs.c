#include <stdio.h>

int main(void) {
  int n, i, j, time = 0, temp;
  int pid[20], at[20], bt[20], ct[20], tat[20], wt[20];
  float avg_tat = 0.0f, avg_wt = 0.0f;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    pid[i] = i + 1;
    printf("Enter arrival time and burst time for P%d: ", pid[i]);
    scanf("%d%d", &at[i], &bt[i]);
  }

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (at[j] > at[j + 1]) {
        temp = at[j];
        at[j] = at[j + 1];
        at[j + 1] = temp;
        temp = bt[j];
        bt[j] = bt[j + 1];
        bt[j + 1] = temp;
        temp = pid[j];
        pid[j] = pid[j + 1];
        pid[j + 1] = temp;
      }
    }
  }

  for (i = 0; i < n; i++) {
    if (time < at[i]) {
      time = at[i];
    }
    time += bt[i];
    ct[i] = time;
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    avg_tat += tat[i];
    avg_wt += wt[i];
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
