#include <limits.h>
#include <stdio.h>

int main() {
  int n, frames_count, i, j, faults = 0, hit, replace_index;
  int reference[50], frames[10], last_used[10];

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
    last_used[i] = -1;
  }

  printf("\nPage\tFrames\n");
  for (i = 0; i < n; i++) {
    hit = 0;

    for (j = 0; j < frames_count; j++) {
      if (frames[j] == reference[i]) {
        hit = 1;
        last_used[j] = i;
        break;
      }
    }

    if (!hit) {
      replace_index = -1;
      for (j = 0; j < frames_count; j++) {
        if (frames[j] == -1) {
          replace_index = j;
          break;
        }
      }

      if (replace_index == -1) {
        int least_recent = INT_MAX;
        for (j = 0; j < frames_count; j++) {
          if (last_used[j] < least_recent) {
            least_recent = last_used[j];
            replace_index = j;
          }
        }
      }

      frames[replace_index] = reference[i];
      last_used[replace_index] = i;
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
