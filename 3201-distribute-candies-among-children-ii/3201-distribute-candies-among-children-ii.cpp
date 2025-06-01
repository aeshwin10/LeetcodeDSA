class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int a = max(0, n - (2 * limit)); a<=min(limit, n); a++){
            int b = min(limit, n-a) - max(0, n-a-limit) + 1;
            ans+= max(0,b);
        }
        return ans;
    }
};