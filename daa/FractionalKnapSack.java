public class FractionalKnapSack {

    public void fractionalKnapSack(double m, int n, double[] w, double[] p) {

        // x[i] stores the fraction of item i taken
        // 1.0 = complete item
        // 0.5 = half item
        // 0.0 = not taken
        double[] x = new double[n];

        // Stores the final maximum profit
        double profit = 0.0;

        // Initially, no item is selected
        // x = {0.0,0.0,0.0.... till the value of n specified}
        for (int i = 0; i < n; i++) {
            x[i] = 0.0;
        }

        // U = Remaining capacity of the knapsack
        double U = m;

        // Declare i outside the loop so it can be used later
        int i;

        // Greedily take complete items until one doesn't fit
        for (i = 0; i < n; i++) {

            // Current item cannot fit completely
            if (w[i] > U) {
                break;
            }

            // Take the complete item
            x[i] = 1.0;

            // Reduce remaining capacity
            U = U - w[i];
        }

        // Take a fraction of the first item that couldn't fit
        if (i < n) {
            x[i] = U / w[i];
        }

        // Print fractions taken and calculate total profit
        for (i = 0; i < n; i++) {

            System.out.println("X[" + i + "] = " + x[i]);

            // Profit = Profit + (Item Profit × Fraction Taken)
            profit += p[i] * x[i];
        }

        System.out.println("Maximum Profit = " + profit);
    }

    public static void main(String[] args) {

        int n = 3;
        double m = 20;

        // Items must already be sorted in decreasing Profit/Weight ratio
        double[] w = {15, 10, 18};
        double[] p = {24, 15, 25};

        FractionalKnapSack obj = new FractionalKnapSack();

        System.out.println("Optimal Solution:");

        obj.fractionalKnapSack(m, n, w, p);
    }
}
