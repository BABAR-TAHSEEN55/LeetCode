#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, i, j, head, initial_head, disk_size, direction, temp, total_seek = 0;
  int request[50];

  printf("Enter number of disk requests: ");
  scanf("%d", &n);
  printf("Enter request queue: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &request[i]);
  }
  printf("Enter initial head position: ");
  scanf("%d", &head);
  printf("Enter disk size: ");
  scanf("%d", &disk_size);
  printf("Enter direction (0 for left, 1 for right): ");
  scanf("%d", &direction);

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (request[j] > request[j + 1]) {
        temp = request[j];
        request[j] = request[j + 1];
        request[j + 1] = temp;
      }
    }
  }

  initial_head = head;
  printf("Seek sequence: %d ", head);

  if (direction == 1) {
    for (i = 0; i < n; i++) {
      if (request[i] >= initial_head) {
        total_seek += abs(head - request[i]);
        head = request[i];
        printf("-> %d ", head);
      }
    }

    total_seek += abs(head - (disk_size - 1));
    head = disk_size - 1;
    printf("-> %d ", head);

    total_seek += abs(head - 0);
    head = 0;
    printf("-> %d ", head);

    for (i = 0; i < n; i++) {
      if (request[i] < initial_head) {
        total_seek += abs(head - request[i]);
        head = request[i];
        printf("-> %d ", head);
      }
    }
  } else {
    for (i = n - 1; i >= 0; i--) {
      if (request[i] <= initial_head) {
        total_seek += abs(head - request[i]);
        head = request[i];
        printf("-> %d ", head);
      }
    }

    total_seek += abs(head - 0);
    head = 0;
    printf("-> %d ", head);

    total_seek += abs(head - (disk_size - 1));
    head = disk_size - 1;
    printf("-> %d ", head);

    for (i = n - 1; i >= 0; i--) {
      if (request[i] > initial_head) {
        total_seek += abs(head - request[i]);
        head = request[i];
        printf("-> %d ", head);
      }
    }
  }

  printf("\nTotal seek operations = %d\n", total_seek);
  return 0;
}
