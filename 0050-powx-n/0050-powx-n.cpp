class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;
        if(m<0){
            m=m*-1;
        }
        long double ans = 1.0;
        while(m>0){
            if(m%2==1){
                ans = ans * x;
                m=m-1;
            }
            else{
                m=m/2;
                x = x*x;
            }
        }
        if(n>0){
            return ans;
        }
        else{
            ans = 1.0/ans;
            return ans;
        }
    }
};