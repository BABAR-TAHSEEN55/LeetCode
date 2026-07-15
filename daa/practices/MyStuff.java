
publicc class MyStuff{
    public void ShortestPath(int cost[][],int S[],int n,int dist[]){

    for(int i = 0;i<=n;i++){
        dist[i] = cost[0][i];
    }

    S[0] =1;
    dist[0]=0;
    for(int i =1;i<n-1;i++){
        int u = mistDist(dist,S,n);
    }


}
public int mistDist(int dist[],int S[],int n){
    int min = Integer.MAX_VALUE;
    int u=-1;
    for(int i =0;i<n;i++){
        if(S[i]!=1 && dist[i]<min){
            min = dist[i];
            u=i;
        }
    }
    return u;

}
}
