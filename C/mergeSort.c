#include <stdio.h>
#define N 20

void Merge(int arr[], int low, int mid, int high) {
  int temp[N];
  int left = low;
  int right = mid + 1;
  int k = low;

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp[k++] = arr[left++];
    } else {
      temp[k++] = arr[right++];
    }
  }

  while (left <= mid) {
    temp[k++] = arr[left++];
  }

  while (right <= high) {
    temp[k++] = arr[right++];
  }

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i];
  }
}

void MergeSort(int arr[], int low, int high) {
  if (low >= high)
    return;
  int mid = (low + high) / 2;
  MergeSort(arr, low, mid);
  MergeSort(arr, mid + 1, high);
  Merge(arr, low, mid, high);
}

int main() {
  int arr[N] = {12, 11, 13, 5, 6, 7};
  int n = 6;

  printf("Original array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Perform Merge Sort
  MergeSort(arr, 0, n - 1);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
