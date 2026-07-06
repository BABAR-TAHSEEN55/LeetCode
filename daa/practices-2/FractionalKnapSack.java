public class FractionalKnapSack {

    public void Knapsack(double m, int n, double w[], double p[]) {

        double x[] = new double[n];
        double U = m;
        double profit = 0.0;

        int i;

        // Initially take nothing
        for (i = 0; i < n; i++) {
            x[i] = 0.0;
        }

        // Take complete items greedily
        for (i = 0; i < n; i++) {

            if (w[i] > U)
                break;

            x[i] = 1.0;
            U -= w[i];
        }

        // Take fraction of first item that doesn't fit
        if (i < n) {
            x[i] = U / w[i];
        }

        // Calculate total profit
        for (i = 0; i < n; i++) {
            System.out.println("x[" + i + "] = " + x[i]);
            profit += p[i] * x[i];
        }

        System.out.println("Maximum Profit = " + profit);
    }

    public static void main(String[] args) {

        int n = 3;
        double m = 20;

        double w[] = {15, 10, 18};
        double p[] = {24, 15, 25};

        FractionalKnapSack obj = new FractionalKnapSack();

        obj.Knapsack(m, n, w, p);
    }
}
