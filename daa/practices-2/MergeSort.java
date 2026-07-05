
public class MergeSort {

    // Recursive Merge Sort Function
    public void MergeSort(int[] a, int low, int high) {

        // Base Case:
        // If there is only one element (or no element),
        // it is already sorted.
        if (low >= high)
            return;

        // Find the middle index
        int mid = (low + high) / 2;

        // Recursively sort the left half
        MergeSort(a, low, mid);

        // Recursively sort the right half
        MergeSort(a, mid + 1, high);

        // Merge the two sorted halves
        Merge(a, low, mid, high);
    }

    // Function to merge two sorted subarrays
    public void Merge(int[] a, int low, int mid, int high) {

        // i -> points to left subarray
        int i = low;

        // j -> points to right subarray
        int j = mid + 1;

        // k -> points to temporary array
        int k = low;

        // Temporary array to store merged result
        int[] b = new int[a.length];

        // Compare elements from both halves
        while (i <= mid && j <= high) {

            // Smaller element goes into temp array
            if (a[i] <= a[j]) {
                b[k] = a[i];
                i++;
            } else {
                b[k] = a[j];
                j++;
            }

            k++;
        }

        // Copy remaining elements from left half
        while (i <= mid) {
            b[k] = a[i];
            i++;
            k++;
        }

        // Copy remaining elements from right half
        while (j <= high) {
            b[k] = a[j];
            j++;
            k++;
        }

        // Copy merged array back into original array
        for (int x = low; x <= high; x++) {
            a[x] = b[x];
        }
    }

    public static void main(String[] args) {

        int[] a = {5, 2, 4, 1};

        MergeSort ms = new MergeSort();

        // Sort the complete array
        ms.MergeSort(a, 0, a.length - 1);

        System.out.println("Sorted Array:");

        for (int num : a) {
            System.out.print(num + " ");
        }
    }
}
