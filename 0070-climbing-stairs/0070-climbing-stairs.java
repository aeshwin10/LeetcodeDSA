class Solution {
    public int climbStairs(int n) {
        if (n<=1) return 1;

        int prev1 = 1;
        int prev2 = 2;
        
        for (int i = 3; i<=n; i++){
            int val = prev1 + prev2; //Similar to Fibbanocci.
            prev1= prev2;
            prev2=val; 
        }
        return prev2;
    }
}