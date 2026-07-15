public class KnapsackDP {

    // Function to solve 0/1 Knapsack
    public static void knapsack(int[] weight, int[] profit, int capacity) {

        int n = weight.length;

        // DP Table
        int[][] dp = new int[n + 1][capacity + 1];

        // Build the DP Table
        for (int i = 1; i <= n; i++) {

            for (int j = 0; j <= capacity; j++) {

                // If current item can fit
                if (weight[i - 1] <= j) {

                    dp[i][j] = Math.max(
                            dp[i - 1][j],                                       // Don't take item
                            profit[i - 1] + dp[i - 1][j - weight[i - 1]]        // Take item
                    );

                } else {

                    // Current item cannot fit
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Print DP Table
        System.out.println("DP Table:");

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= capacity; j++) {
                System.out.print(dp[i][j] + "\t");
            }
            System.out.println();
        }

        // Maximum Profit
        System.out.println("\nMaximum Profit = " + dp[n][capacity]);

        // Traceback to find selected items
        System.out.print("Selected Items: ");

        int j = capacity;

        for (int i = n; i >= 1; i--) {

            if (dp[i][j] != dp[i - 1][j]) {

                System.out.print(i + " ");

                j = j - weight[i - 1];
            }
        }

        System.out.println();
    }

    public static void main(String[] args) {

        // Weights of items
        int[] weight = {2, 3, 4};

        // Profits of items
        int[] profit = {1, 2, 5};

        // Knapsack Capacity
        int capacity = 5;

        knapsack(weight, profit, capacity);
    }
}
