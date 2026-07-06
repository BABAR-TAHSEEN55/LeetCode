// import java.util.*;
//
// public class NQueens {
//     int n;
//     int x[];
//
//     public NQueens(int n) {
//         this.n = n;
//         x = new int[n];
//     }
//
//     public void queens(int k, int n) {
//         for (int i = 0; i < n; i++) {
//             if (place(k, i)) {
//                 x[k] = i;
//                 if (k == n - 1) {
//                     displayX();
//                 } else {
//                     queens(k + 1, n);
//                 }
//             }
//         }
//     }
//
//     public void displayX() {
//         for (int i = 0; i < n; i++) {
//             System.out.print(x[i] + " ");
//         }
//         System.out.println();
//     }
//
//     public boolean place(int k, int i) {
//         for (int j = 0; j < k; j++) {
//             if (x[j] == i || Math.abs(x[j] - i) == Math.abs(j - k)) {
//                 return false;
//             }
//         }
//         return true;
//     }
//
//     public static void main(String[] args) {
//         int n = 4;
//         NQueens qq = new NQueens(n);
//         qq.queens(0, n);
//     }
// }

import java.util.*;

public class NQueens {

    // n = size of the chessboard (n x n)
    int n;

    // x[row] = column where the queen is placed in that row.
    // Example:
    // x = [1, 3, 0, 2]
    // Row 0 -> Column 1
    // Row 1 -> Column 3
    // Row 2 -> Column 0
    // Row 3 -> Column 2
    int x[];

    // Constructor
    public NQueens(int n) {

        // Store board size
        this.n = n;

        // Create array to store queen positions
        x = new int[n];
    }

    // k = current row where we are trying to place a queen
    // i = current coloum
    public void queens(int k, int n) {

        // Try placing queen in every column of current row
        for (int i = 0; i < n; i++) {

            // Check whether queen can be placed
            if (place(k, i)) {

                // Place queen at row k and column i
                x[k] = i;

                // If last row reached,
                // one complete solution is found
                if (k == n - 1) {

                    // Print the solution
                    displayX();

                } else {

                    // Move to next row
                    queens(k + 1, n);

                    // No explicit "remove queen" is needed.
                    // During backtracking x[k] will simply
                    // get overwritten by the next column value.
                }
            }

            // If place() returns false,
            // simply try next column.
        }

        // When all columns are tried,
        // recursion automatically returns to previous row
        // (this is backtracking).
    }

    // Prints one valid solution
    public void displayX() {

        // Print column position of queen in each row
        for (int i = 0; i < n; i++) {
            System.out.print(x[i] + " ");
        }

        System.out.println();
    }

    // Checks whether queen can be placed
    // at row k and column i
    public boolean place(int k, int i) {

        // Compare with every previously placed queen
        // (rows 0 to k-1)
        for (int j = 0; j < k; j++) {

            // Condition 1:
            // Same column
            //
            // Example:
            // Existing queen -> Row 1 Column 2
            // New queen      -> Row 3 Column 2
            //
            // Not allowed.
            if (x[j] == i)

                return false;

            // Condition 2:
            // Same diagonal
            //
            // Two queens are on the same diagonal when:
            //
            // |column difference| == |row difference|
            //
            // Example:
            // Existing queen -> (1,2)
            // New queen      -> (3,4)
            //
            // |2-4| = 2
            // |1-3| = 2
            //
            // Equal ⇒ Same diagonal ⇒ Invalid
            //
            // Example:
            // Existing queen -> (0,1)
            // New queen      -> (2,3)
            //
            // |1-3| = 2
            // |0-2| = 2
            //
            // Equal ⇒ Invalid
            if (Math.abs(x[j] - i) == Math.abs(j - k))

                return false;
        }

        // No conflicts found
        return true;
    }

    public static void main(String[] args) {

        // Board size
        int n = 4;

        // Create object
        NQueens qq = new NQueens(n);

        // Start placing queens from row 0
        qq.queens(0, n);
    }
}
