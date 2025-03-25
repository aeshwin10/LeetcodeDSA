class Solution {
public:
    int climbStairs(int n){        //SC     
        if(n==1 || n==2){
            return n;
        }
        int num1 = 1;
        int num2 = 2;
        for(int i=3; i<=n; i++){
            int num3 = num2 + num1;
            num1 = num2;
            num2 = num3;
        }
        return num2;
    }
};