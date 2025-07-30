
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int i, j, k, n, T;
  int P[10];
  int AT[10] = {0};
  int BT[10] = {0};
  int CT[10] = {0};
  int TAT[10] = {0};
  int WT[10] = {0};
  float TotalTat = 0, TotalWt = 0;

  // NUmber of Processes
  printf("Enter No of Processes: ");
  scanf("%d", &n);

  // Input AT & BT
  for (i = 0; i < n; i++) {
    P[i] = i + 1;
    printf("Enter Arrival Time for P [%d]", i);
    scanf("%d", &AT[i]);
    printf("Enter Burst Time for P [%d]", i);
    scanf("%d", &BT[i]);
  }

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (BT[j] > BT[j + 1]) {
        T = BT[j];
        BT[j] = BT[j + 1];
        BT[j + 1] = T;

        T = AT[j];
        AT[j] = AT[j + 1];
        AT[j + 1] = T;

        T = P[j];
        P[j] = P[j + 1];
        P[j + 1] = T;
      }
    }
  }
  int sum = AT[0];
  for (i = 0; i < n; i++) {
    sum += BT[i];
    CT[i] = sum;

    TAT[i] = CT[i] - AT[i];
    WT[i] = TAT[i] - BT[i];
  }
  printf("P\tAT\tBt\tCT\tTAT\tWT\n");
  for (i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i], AT[i], BT[i], CT[i], TAT[i],
           WT[i]);
  }
}
