#include <stdio.h>

int main() {
  int n, m, i, j, k, process;
  int allocation[10][10], maximum[10][10], need[10][10], available[10];
  int request[10], work[10], finish[10], safe_sequence[10], count = 0;

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
    work[j] = available[j];
  }

  printf("Enter process number requesting resources (0 to %d): ", n - 1);
  scanf("%d", &process);
  printf("Enter request vector:\n");
  for (j = 0; j < m; j++) {
    scanf("%d", &request[j]);
  }

  for (j = 0; j < m; j++) {
    if (request[j] > need[process][j]) {
      printf("Error: request exceeds process need.\n");
      return 1;
    }
    if (request[j] > available[j]) {
      printf("Resources not available. Request cannot be granted now.\n");
      return 1;
    }
  }

  for (j = 0; j < m; j++) {
    available[j] -= request[j];
    allocation[process][j] += request[j];
    need[process][j] -= request[j];
    work[j] = available[j];
  }

  for (i = 0; i < n; i++) {
    finish[i] = 0;
  }

  while (count < n) {
    int found = 0;

    for (i = 0; i < n; i++) {
      if (!finish[i]) {
        int can_run = 1;
        for (j = 0; j < m; j++) {
          if (need[i][j] > work[j]) {
            can_run = 0;
            break;
          }
        }

        if (can_run) {
          for (k = 0; k < m; k++) {
            work[k] += allocation[i][k];
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
    printf("Request granted. System remains safe.\nSafe sequence: ");
    for (i = 0; i < n; i++) {
      printf("P%d", safe_sequence[i]);
      if (i != n - 1) {
        printf(" -> ");
      }
    }
    printf("\n");
  } else {
    printf("Request denied. System would enter an unsafe state.\n");
  }

  return 0;
}
