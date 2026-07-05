public class GraphColoring2{
    int n,m;
    int cost[][];
    int x[];
    public GraphColoring2(){
        n = 5;
        m=3;

        cost = new int[][] {
            {0,1,0,1,1},
            {1,0,1,0,1},
            {0,1,0,1,0},
            {1,0,1,0,1},
            {1,1,0,1,0}
        };
        x = new int[n];
    }

    public void nextValue(int k){
        int j;
        do {
            x[k] = (x[k]+1)% (m+1);
            if(x[k]==0) return;

            for(j=0;j<n;j++){

            }
            
        } while (true);

    }
    public void mColoring(){}
    public void display(){}
}
