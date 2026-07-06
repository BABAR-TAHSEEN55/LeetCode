public class AllPairsShortestPath {

    int n;
    int cost[][];
    int A[][];

    // Constructor
    public AllPairsShortestPath() {

        n = 3;

        // Cost adjacency matrix
        cost = new int[][] {
            {0, 4, 11},
            {6, 0, 2},
            {3, Integer.MAX_VALUE, 0}
        };

        // Matrix to store shortest paths
        A = new int[n][n];
    }

    // Floyd-Warshall Algorithm
    public void AllPairs() {

        // Copy cost matrix into A
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                A[i][j] = cost[i][j];

        // Find shortest paths
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    A[i][j] = minValue(A[i][j], A[i][k] + A[k][j]);
    }

    // Returns the minimum of two values
    public int minValue(int x, int y) {
        if (x < y)
            return x;
        else
            return y;
    }

    // Display shortest path matrix
    public void displayA() {

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++)
                System.out.print(A[i][j] + "\t");

            System.out.println();
        }
    }

    // Driver method
    public static void main(String[] args) {

        AllPairsShortestPath apsp = new AllPairsShortestPath();

        apsp.AllPairs();

        apsp.displayA();
    }
}
