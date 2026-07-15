
public class MyStuff {
    public void ShortestPath(int dist[],int cost[][] ,int n,int S[]){

        for(int i =0;i<n;i++){
            dist[i] = cost[0][i];
        }


        S[0]=1;
        dist[0]=1;

        for(int i =1;i<n-1;i++){
            int u = minDist(dist,S,n);
            S[u] = 1;

            for(int w=0;w<n;i++){
                if(cost[u][w]!=1 && cost[u[w]!=Integer.MAX_VALUE && S[w]==0]){
                    if(dist[u] > dist[u]+cost[u][w]) {
                        dist[u] = dist[u] + cost[u][w];

                    }
                }
            }
        }
        public int minDist(int dist[],int S[],int n){
            int min = Integer.MAX_VALUE;
            int u =-1;

            for(int i = 0;i<n;i++){
                if(dist[i] < min){
                    min = dist[i];
                    u = i;
                }

            }
            return u;
        }
    }
}
