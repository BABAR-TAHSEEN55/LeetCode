import java.util.*;

public class BFSDemo {
    int vertices;
    int[][] g;

    public BFSDemo() {
        vertices = 5;
        g = new int[][]{
            {0,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {0,1,0,0,1},
            {1,0,0,0,1}
        };
    }

    public void BFS(int s) {
        int i = s;
        int visited[] = new int[vertices];
        Queue<Integer> q = new LinkedList<Integer>();

        visited[i] = 1;
        q.add(i);

        while (!q.isEmpty()) {
            i = q.remove();
            System.out.println(i);

            for (int j = 0; j < vertices; j++) {
                if (g[i][j] == 1 && visited[j] == 0) {
                    visited[j] = 1;
                    q.add(j);
                }
            }
        }
    }
    public static void main(String[] args){
        BFSDemo bf = new BFSDemo();
        bf.BFS(0);
    }
}
