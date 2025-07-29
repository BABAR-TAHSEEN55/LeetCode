
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i, j, k, l;
  int AT[10] = {0};
  int CT[10] = {0};
  int BT[10] = {0};
  int WT[10] = {0};
  int TAT[10] = {0};
  float TotalWT = 0, TotalTAT = 0;
  printf("Enter No. of Processes : ");
  scanf("%d", &n);
  // Input for AT and BT
  for (i = 1; i <= n; i++) {
    printf("Enter Arrival Time for P[i]");
    scanf("%d", &AT[i]);
    printf("Enter Burst Time for P[%d]", n);
    scanf("%d", &BT[i]);
  }
  // CT Assuming everything is sorted
  int sum = AT[0];
  for (j = 1; j <= n; j++) {
    sum += BT[j];
    CT[j] = sum;
  }
  for (k = 1; k <= n; k++) {
    TAT[k] = CT[k] - AT[k];
    TotalTAT += TAT[k];
  }
  for (k = 1; k <= n; k++) {
    WT[k] = TAT[k] - BT[k];
    TotalWT += WT[k];
  }
  printf("P\tAT\tBT\tCT\tTAT\tWT\n");
  for (i = 1; i <= n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", n, AT[i], BT[i], CT[i], TAT[i], WT[i]);
  }
  printf("TotalTAT : %f\n", TotalTAT / n);
}
