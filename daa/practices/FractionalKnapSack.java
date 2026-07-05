
public class FractionalKnapSack{
    public void FractionalKnapSack(double m,int n,double w[],double p[]){

        double x[] = new double[n];
        
        double U = m;
        int i;
        for(i=0;i<n;i++){
            x[i]= 0.0;
        }
        for(i=0;i<n;i++){
            if(w[i]>U){
                break;
            }
            x[i] = 1.0;
            U-=w[i];
        }
        if(i<n){
            x[i] = U/w[i];
        }

        for(i=0;i<n;i++){
            System.out.println("X ["+i+"] = "+x[i]);
            profit = profit+p[i]*x[i];
        }

    }
}
