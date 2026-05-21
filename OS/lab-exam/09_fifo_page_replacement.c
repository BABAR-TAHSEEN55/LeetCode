#include <stdio.h>

int main() {
  int n, frames_count, i, j, pointer = 0, faults = 0, hit;
  int reference[50], frames[10];

  printf("Enter number of page references: ");
  scanf("%d", &n);
  printf("Enter reference string: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &reference[i]);
  }

  printf("Enter number of frames: ");
  scanf("%d", &frames_count);

  for (i = 0; i < frames_count; i++) {
    frames[i] = -1;
  }

  printf("\nPage\tFrames\n");
  for (i = 0; i < n; i++) {
    hit = 0;

    for (j = 0; j < frames_count; j++) {
      if (frames[j] == reference[i]) {
        hit = 1;
        break;
      }
    }

    if (!hit) {
      frames[pointer] = reference[i];
      pointer = (pointer + 1) % frames_count;
      faults++;
    }

    printf("%d\t", reference[i]);
    for (j = 0; j < frames_count; j++) {
      if (frames[j] == -1) {
        printf("- ");
      } else {
        printf("%d ", frames[j]);
      }
    }
    printf("\n");
  }

  printf("Page Faults = %d\n", faults);
  return 0;
}
