class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long totSum = n*(n+1)/2;
        long long sum1 = 0;
        for(int i=1; i*m<=n; i++){
            sum1+=(i*m);
        }
        long long sum2 = totSum - sum1;
        return (sum2 - sum1);
    }
};