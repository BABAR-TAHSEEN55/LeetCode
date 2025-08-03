
#include <stdio.h>

int main() {
  int n, i, j = 0, k, a[50], frame[10], avail, count = 0, no;

  printf("Enter the length of Reference String: ");
  scanf("%d", &n);

  printf("Enter Reference String:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  printf("Enter Frame Size: ");
  scanf("%d", &no);

  // Initialize frames to -1 (empty)
  for (i = 0; i < no; i++) {
    frame[i] = -1;
  }

  printf("\nRef_String\tFrame Content\n");

  for (i = 0; i < n; i++) {
    printf("%d\t\t", a[i]);
    avail = 0;

    // Check if page already in memory
    for (k = 0; k < no; k++) {
      if (frame[k] == a[i]) {
        avail = 1;
        break;
      }
    }

    // If not available, do FIFO replacement
    if (avail == 0) {
      frame[j] = a[i];
      j = (j + 1) % no;
      count++;
    }

    // Print current frame status
    for (k = 0; k < no; k++) {
      if (frame[k] != -1)
        printf("%d\t", frame[k]);
      else
        printf("-\t");
    }
    printf("\n");
  }
}
