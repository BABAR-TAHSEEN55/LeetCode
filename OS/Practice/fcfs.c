
#include <stdio.h>

int main() {
  int n, i, j, k;
  int AT[10] = {0};
  int BT[10] = {0};
  int CT[10] = {0};
  int TAT[10] = {0};
  int WT[10] = {0};
  float TotalTAT = 0, TotalWt = 0;

  // Number of Processes
  printf("Enter Number of Processes : ");
  scanf("%d", &n);
  // Taking Input for Arrival Time & Burst Time
  for (i = 1; i <= n; i++) {
    printf("Enter Arrival Time for P[%d]", i);
    scanf("%d", &AT[i]);
    printf("Enter Burst Time for P[i]");
    scanf("%d", &BT[i]);
  }
  // Calculate CT
  int sum = AT[0];
  for (j = 1; j <= n; j++) {
    sum += AT[j];
    CT[j] = sum;
  }
  // Calculating TAT
  for (k = 1; k <= n; k++) {
    TAT[k] = CT[k] - AT[k];
    TotalTAT += TAT[k];
  }
  for (k = 1; k <= n; k++) {
    WT[k] = TAT[k] - BT[k];
    TotalWt += WT[k];
  }
  printf("P\tAT\tBT\tCT\tTAT\tWT\n");
  for (j = 1; j <= n; j++) {
    printf("P%d\t%d\%d\t%d\t%d\t%d\n", n, AT[j], BT[j], CT[j], TAT[j], WT[j]);
  }
}
