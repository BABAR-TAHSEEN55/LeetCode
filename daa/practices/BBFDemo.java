
public class BBFDemo{
    int vertices;
    int g[][];
    public class BBFDemo(){
        vertices = 5;
        g = new int[][]{
            {0,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {0,1,0,0,1},
            {1,0,0,0,1}
        }
    }
    public void BFS(int s){
        int i =s;
        Queue<Integer> q= new LinkedList<Integer>();
        int visited[] = new int[visited];
        visited[i]=1;
        q.add(i);
        while(!q.isEmpty()){
            i = q.remove();
            for(int j = 0;j<vertices;j++){
                if(g[i][j]==1 && visited[j]==0){
                    visited[j]=1;
                    q.add(j);
                }
            }
        }
    }
}
