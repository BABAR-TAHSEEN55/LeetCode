public class QuickSortDemo {

    // Quick Sort function
    public void QuickSort(int a[], int low, int high) {

        // Continue only if there is more than one element
        if (low < high) {

            // Partition the array and get the pivot's correct position
            int p = Partition(a, low, high);

            // Sort left half
            QuickSort(a, low, p - 1);

            // Sort right half
            QuickSort(a, p + 1, high);
        }
    }

    // Partition function
    public int Partition(int a[], int low, int high) {

        // Choose the first element as pivot
        int pivot = a[low];

        // i moves from left to right
        int i = low + 1;

        // j moves from right to left
        int j = high;

        // Continue until both pointers cross
        while (true) {

            // Move i until an element greater than pivot is found
            while (i <= j && a[i] <= pivot) {
                i++;
            }

            // Move j until an element smaller than or equal to pivot is found
            while (i <= j && a[j] > pivot) {
                j--;
            }

            // If pointers have crossed, partition is complete
            if (i > j) {
                break;
            }

            // Otherwise swap the incorrect elements
            Swap(a, i, j);
        }

        // Put pivot into its correct position
        Swap(a, low, j);

        // Return pivot index
        return j;
    }

    // Swap two elements
    public void Swap(int a[], int i, int j) {

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void main(String[] args) {

        int a[] = {4, 9, 1, 22, 2, 16, 100, 39, 92, 19};

        QuickSortDemo obj = new QuickSortDemo();

        obj.QuickSort(a, 0, a.length - 1);

        System.out.println("Sorted Array:");

        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
