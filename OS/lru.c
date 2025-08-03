
#include <stdio.h>
int main() {
  int i, j, k, min, rs[25], m[10], count[10], flag[25];
  int n, f, pf = 0, next = 1;
  printf("Enter the length of Reference String : ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &rs[i]);
    flag[i] = 0;
  }
  printf("Enter the Frame Size : ");
  scanf("%d", &f);
  for (i = 0; i < f; i++) {
    m[i] = -1;
    count[i] = 0;
  }
  printf("The LRU Replacement Process is : \n");
  for (i = 0; i < f; i++) {
    int found = 0;
    for (j = 0; j < f; j++) {
      if (m[i] == rs[i]) {
        found = 1;
        count[j] = next++;
        break;
      }
    }

    if (!found) {
      pf++;
    }
    // Filling up Empty Frames
    for (j = 0; j < f; j++) {
      if (m[i] == -1) {
        m[i] = rs[i];
        count[i] = next++;
        found = 1;
        break;
      }
    }
    if (!found) {
      min = 0;
      for (j = 1; j < f; j++) {
        if (count[j] < count[min]) {
          min = j;
        }
      }
      m[min] = rs[i];
      count[min] = next++;
    }
  }
}
