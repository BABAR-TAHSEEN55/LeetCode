
#include <stdio.h>

int main() {
  float TotalTAT = 0, TotatWT = 0;
  int i;
  int AT[10];
  int BT[10];
  int CT[10];
  int TAT[10];
  int WT[10];
  int n;
  printf("Enter No. of Process : ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter Arrival Time for P[%d]", i);
    scanf("%d", &AT[i]);
    printf("Enter Burst Time for P[%d]", i);
    scanf("%d", &BT[i]);
  }
  //
  int sum = AT[0];
  for (i = 0; i < n; i++) {
    sum += BT[i];
    CT[i] = sum;
  }
  for (i = 0; i < n; i++) {
    TAT[i] = CT[i] - AT[i];
    WT[i] = TAT[i] - BT[i];
    TotalTAT += TAT[i];
    TotatWT += WT[i];
  }
  printf("P\tAT\tBT\tCT\tTAT\tWT\n");
  for (i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, AT[i], BT[i], CT[i], TAT[i], WT[i]);
  }
  printf("Avg WT : %f", TotatWT/n);
  printf("Avg TAT : %f", TotalTAT/n);
}
