public class DFSGraph {

    // Adjacency matrix representing the graph
    int[][] g;

    // Total number of vertices
    int vertices;

    // Keeps track of visited vertices
    int[] visited;

    // Constructor
    public DFSGraph() {

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

        // Initially, no vertex has been visited
        visited = new int[vertices];
    }

    // Recursive DFS starting from vertex s
    public void DFS(int s) {

        // Visit the vertex only if it hasn't been visited
        if (visited[s] == 0) {

            // Mark current vertex as visited
            visited[s] = 1;

            // Process the current vertex
            System.out.println(s);

            // Check all neighbours of current vertex
            for (int j = 0; j < vertices; j++) {

                // If there is an edge and neighbour is unvisited
                if (g[s][j] == 1 && visited[j] == 0) {

                    // Recursively visit the neighbour
                    DFS(j);
                }
            }
        }
    }

    public static void main(String[] args) {

        // Create graph object
        DFSGraph d = new DFSGraph();

        // Start DFS from vertex 0
        d.DFS(0);
    }
}
