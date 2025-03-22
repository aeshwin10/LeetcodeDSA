class Solution {
public:
    int climbStairs(int n) {  //Time Complexity -> O(n). Space Complexity -> O(1)
        if(n==1 || n==2){
            return n;
        }
        int a=1;
        int b=2;
        for(int i=3; i<=n; i++){
            int c=a+b;
            a = b;
            b = c;
        }
        return b;
    }
};