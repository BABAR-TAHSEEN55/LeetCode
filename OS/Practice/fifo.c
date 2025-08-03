
#include <stdio.h>
int main() {

  int i, j = 0, k, a[50], frame[10], avail, count = 0, n, no;
  printf("Enter Reference String size : ");
  scanf("%d", &n);
  printf("Enter Reference String : ");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printf("Enter Frame size : ");
  scanf("%d", &no);
  // Initialize Frame TO -1
  for (i = 0; i < no; i++) {
    frame[i] = -1;
  }
  printf("\tReference_String\tFrames\n");
  for (i = 0; i < n; i++) {
    printf("%d\t\t", a[i]);
    avail = 0;

    for (k = 0; k < no; k++) {
      if (frame[k] == a[i]) {
        count++;
        avail = 1;
        break;
      }
    }
    if (avail == 0) {
      frame[j] = a[i];
      j = (j + 1) % no;
      count++;
    }
    for (k = 0; k < no; k++) {
      if (frame[k] == -1) {
        printf("-\t");
      } else {
        printf("%d\t", frame[k]);
      }
    }
    printf("\n");
  }
}
