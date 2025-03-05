class Solution {
public:
    long long findSquares(long long n){
        if(n==2){
            return 5;
        }
        else{
            return findSquares(n-1) + (long long)4*(n-2) + 4;
        }
    }

    long long coloredCells(int n) {
        if(n==1){
            return 1;
        }

        long long ans = findSquares(n);
        return ans;        

    }
};