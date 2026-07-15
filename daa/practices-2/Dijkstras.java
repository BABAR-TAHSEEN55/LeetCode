public class Dijkstra_SSSP {

    // Function to find shortest path from source vertex (0)
    public void shortestPaths(int cost[][], int dist[], int S[], int n) {

        // Step 1: Initialize distances with direct edge costs from source
        for (int i = 0; i < n; i++)
            dist[i] = cost[0][i];

        // Step 2: Mark source vertex as visited (finalized)
        S[0] = 1;

        // Distance from source to itself is always 0
        dist[0] = 0;

        // Step 3: Repeat until all vertices are processed
        for (int i = 1; i < n - 1; i++) {

            // Pick the unvisited vertex with minimum distance
            int u = minDist(dist, S, n);

            // Mark selected vertex as visited
            S[u] = 1;

            // Check every neighbour of vertex u
            for (int w = 0; w < n; w++) {

                // Process only if:
                // 1. Edge exists
                // 2. Edge weight is not INF
                // 3. Neighbour is not yet visited
                if (cost[u][w] != 0 &&
                    cost[u][w] != Integer.MAX_VALUE &&
                    S[w] == 0) {

                    // Relaxation:
                    // If going through u gives a shorter path,
                    // update the distance.
                    if (dist[w] > dist[u] + cost[u][w]) {
                        dist[w] = dist[u] + cost[u][w];
                    }
                }
            }
        }
    }

    // Finds the unvisited vertex having the minimum distance
    public int minDist(int dist[], int S[], int n) {

        // Assume minimum distance is infinity
        int min = Integer.MAX_VALUE;

        // Stores index of minimum distance vertex
        int u = -1;

        // Check every vertex
        for (int i = 0; i < n; i++) {

            // Select only unvisited vertices
            // Update if a smaller distance is found
            if (S[i] != 1 && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        // Return vertex having smallest distance
        return u;
    }

    // Displays shortest distance from source to every vertex
    public void displayDist(int dist[], int n) {

        System.out.println("Shortest Distances:");

        for (int i = 0; i < n; i++) {

            // Vertex cannot be reached
            if (dist[i] == Integer.MAX_VALUE)
                System.out.println(i + " -> INF");

            // Print shortest distance
            else
                System.out.println(i + " -> " + dist[i]);
        }
    }

    public static void main(String args[]) {

        // Represents no edge between two vertices
        int INF = Integer.MAX_VALUE;

        // Cost (Adjacency) Matrix
        int cost[][] = {

            {0,50,45,10,INF,INF},
            {INF,0,10,15,INF,INF},
            {INF,INF,0,INF,30,INF},
            {20,INF,INF,0,15,INF},
            {INF,20,35,INF,0,3},
            {INF,INF,INF,INF,INF,0}

        };

        // Stores shortest distances
        int dist[] = new int[6];

        // Visited array (0 = Not Visited, 1 = Visited)
        int S[] = new int[6];

        // Create object
        Dijkstra_SSSP d = new Dijkstra_SSSP();

        // Find shortest paths from source vertex 0
        d.shortestPaths(cost, dist, S, 6);

        // Display final shortest distances
        d.displayDist(dist, 6);
    }
}
