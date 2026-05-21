#include <stdio.h>

int main() {
  int n, m, i, j, k;
  int allocation[10][10], maximum[10][10], need[10][10], available[10];
  int finish[10] = {0}, safe_sequence[10], count = 0;

  printf("Enter number of processes: ");
  scanf("%d", &n);
  printf("Enter number of resource types: ");
  scanf("%d", &m);

  printf("Enter allocation matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &allocation[i][j]);
    }
  }

  printf("Enter maximum matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &maximum[i][j]);
      need[i][j] = maximum[i][j] - allocation[i][j];
    }
  }

  printf("Enter available resources:\n");
  for (j = 0; j < m; j++) {
    scanf("%d", &available[j]);
  }

  while (count < n) {
    int found = 0;

    for (i = 0; i < n; i++) {
      if (!finish[i]) {
        int can_run = 1;
        for (j = 0; j < m; j++) {
          if (need[i][j] > available[j]) {
            can_run = 0;
            break;
          }
        }

        if (can_run) {
          for (k = 0; k < m; k++) {
            available[k] += allocation[i][k];
          }
          safe_sequence[count++] = i;
          finish[i] = 1;
          found = 1;
        }
      }
    }

    if (!found) {
      break;
    }
  }

  if (count == n) {
    printf("System is in a safe state.\nSafe sequence: ");
    for (i = 0; i < n; i++) {
      printf("P%d", safe_sequence[i]);
      if (i != n - 1) {
        printf(" -> ");
      }
    }
    printf("\n");
  } else {
    printf("System is not in a safe state.\n");
  }

  return 0;
}
