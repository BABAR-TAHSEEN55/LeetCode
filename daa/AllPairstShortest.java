
public class AllPairsShortestPath{
    int n;
    int cost[][];
    int A[][];
    public AllPairsShortestPath(){
        cost = new int[][]{
        {0,4,11},{6,0,Integer.MAX_VALUE},{0,Integer.MAX_VALUE,4};
        };
        A = new  int[][];
        n = 3;
    }
    public void FW(){
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                A[i][j]=cost[i][j];
            }
        }

        for(int k=0;k<n;k++){
            for(int i =0;i<n;i++){
                for(int j=0;j<n;j++){
                    A[i][j]=minValue(A[i][j],A[i][k]+A[k][j]);
                }
            }
        }
    }
    public int minValue(int x, int y){
        if(x<y){
            return x;
        }else{
            return y;
        }
    }

    public void display(){
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                System.out.println("Values are as follows"+A[i][j]);
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        AllPairsShortestPath apsp = new AllPairsShortestPath();
        apsp.FW();
        apsp.display();
        
    }
}
