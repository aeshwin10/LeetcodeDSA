class Solution {
    public double myPow(double x, int n) {
        long N = n;
        if (n==0 || N==0){
            return 1.0;
        }
    
        if (N < 0) {
            N = -N;
            x = 1 / x;
        }
        if(N%2==0){
            double t=myPow(x,(int) (N/2));
            return(t*t);
        }
        else{
            double t=myPow(x,(int)(N-1));
            return(x*t);
        }  
    }
}