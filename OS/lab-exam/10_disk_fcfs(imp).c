#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i, head, total_seek = 0;
  int request[50];

  printf("Enter number of disk requests: ");
  scanf("%d", &n);
  printf("Enter request queue: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &request[i]);
  }
  printf("Enter initial head position: ");
  scanf("%d", &head);

  printf("Seek sequence: %d ", head);
  for (i = 0; i < n; i++) {
    total_seek += abs(head - request[i]);
    head = request[i];
    printf("-> %d ", head);
  }

  printf("\nTotal seek operations = %d\n", total_seek);
  return 0;
}
