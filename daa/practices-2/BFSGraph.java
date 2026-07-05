import java.util.*;

public class BFSGraph {

    // Adjacency matrix representing the graph
    int[][] g;

    // Total number of vertices
    int vertices;

    // Constructor
    public BFSGraph() {

        vertices = 5;

        // Graph representation
        // 0 -- 1
        // |    |
        // 2 -- 3 -- 4
        g = new int[][] {
            {0, 1, 1, 0, 0},
            {1, 0, 0, 1, 0},
            {1, 0, 0, 1, 0},
            {0, 1, 1, 0, 1},
            {0, 0, 0, 1, 0}
        };
    }

    // BFS traversal starting from vertex s
    public void BFS(int s) {

        // Stores whether a vertex has been visited
        int[] visited = new int[vertices];

        // Queue used for BFS (FIFO)
        Queue<Integer> q = new LinkedList<>();

        // Mark starting vertex as visited
        visited[s] = 1;

        // Add starting vertex to queue
        q.add(s);

        // Continue until queue becomes empty
        while (!q.isEmpty()) {

            // Remove the front vertex from queue
            int i = q.remove();

            // Visit (print) the vertex
            System.out.println(i);

            // Check all neighbours of current vertex
            for (int j = 0; j < vertices; j++) {

                // If there is an edge and the neighbour is not visited
                if (g[i][j] == 1 && visited[j] == 0) {

                    // Mark neighbour as visited
                    visited[j] = 1;

                    // Add neighbour to queue
                    q.add(j);
                }
            }
        }
    }

    public static void main(String[] args) {

        // Create graph object
        BFSGraph b = new BFSGraph();

        // Start BFS from vertex 0
        b.BFS(0);
    }
}
