public class GraphColoring {

    int n;          // Number of vertices
    int m;          // Number of available colors
    int cost[][];   // Adjacency matrix of the graph
    int x[];        // x[i] stores the color assigned to vertex i

    public GraphColoring() {

        n = 5;      // Total vertices

        // Adjacency matrix
        // 1 = Edge exists
        // 0 = No edge
        cost = new int[][] {
            {0,1,0,1,1},
            {1,0,1,0,1},
            {0,1,0,1,0},
            {1,0,1,0,1},
            {1,1,0,1,0}
        };

        m = 3;          // Total colors available
        x = new int[n]; // Initially all colors are 0 (unassigned)
    }

    // Finds the next valid color for vertex k
    public void nextValue(int k) {

        do {

            int j;

            // Move to the next color
            // Cycles like 0 -> 1 -> 2 -> 3 -> 0
            x[k] = (x[k] + 1) % (m + 1);

            // Came back to 0 => Tried all colors, none worked
            if (x[k] == 0)
                return;

            // Check current color with every other vertex
            for (j = 0; j < n; j++) {

                // If adjacent AND same color => Invalid color
                if ((cost[k][j] != 0) && (x[k] == x[j]))
                    break;
            }

            // j==n means loop completed without conflict
            // Current color is valid
            if (j == n)
                return;

            // Otherwise try the next color

        } while (true);
    }

    // Prints one valid coloring
    public void display() {

        for (int i = 0; i < n; i++)
            System.out.print(x[i] + "\t");

        System.out.println();
    }

    // Recursive Backtracking Function
    public void mColoring(int k) {

        do {

            // Assign the next valid color to vertex k
            nextValue(k);

            // No valid color found -> Backtrack
            if (x[k] == 0)
                return;

            // If last vertex is colored, print the solution
            if (k == n - 1)
                display();

            // Otherwise color the next vertex
            else
                mColoring(k + 1);

            // After returning, loop continues
            // to try another color for the current vertex

        } while (true);
    }

    public static void main(String args[]) {

        GraphColoring g = new GraphColoring();

        // Start coloring from vertex 0
        g.mColoring(0);
    }
}
