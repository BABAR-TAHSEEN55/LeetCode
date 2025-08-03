
#include <stdio.h>
int main() {
  int j, i, t, n;
  float totalTAT = 0, totalWT = 0;
  int AT[10];
  int BT[10];
  int CT[10];
  int TAT[10];
  int WT[10];
  int P[10];
  printf("Enter no. Of Processes : ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    /* P[i] = i + 1; */
    printf("Enter Arrival Time for P[%d]", i);
    scanf("%d", &AT[i]);
    printf("Enter Burst Time for P[%d]", i);
    scanf("%d", &BT[i]);
  }
  // Arranging BT
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (BT[j] > BT[j + 1]) {
        t = BT[j];
        BT[j] = BT[j + 1];
        BT[j + 1] = t;

        t = AT[j];
        AT[j] = AT[j + 1];
        AT[j + 1] = t;

        t = P[j];
        P[j] = P[j + 1];
        P[j + 1] = t;
      }
    }
  }
  int sum = AT[0];
  for (i = 0; i < n; i++) {
    sum += BT[i];
    CT[i] = sum;
  }
  for (i = 0; i < n; i++) {
    TAT[i] = CT[i] - AT[i];
    WT[i] = TAT[i] - BT[i];
    totalTAT += TAT[i];
    totalWT += WT[i];
  }
  printf("P\tAT\tBT\tCT\tTAT\tWT\n");
  for (i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, AT[i], BT[i], CT[i], TAT[i], WT[i]);
  }
  printf("Avg TAT : %f\n", totalTAT / n);
  printf("Avg WT : %f\n", totalWT / n);
}
