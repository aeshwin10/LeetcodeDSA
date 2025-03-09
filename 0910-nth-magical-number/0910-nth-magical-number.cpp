class Solution {
public:
    const int mod = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long long ans;
        long long low = min(a, b);
        long long high = n * 1ll * min(a,b);
        while(low<=high){
            long long mid = (low+high)/2;
            long long divACnt = mid/a;
            long long divBCnt = mid/b;
            long long lcm = (a*b) / __gcd(a, b);
            long long divBothCnt = mid/lcm;
            long long x = (divACnt - divBothCnt)  + divBCnt; 
            if(x==n){
                ans = mid;
                high = mid - 1;
            }
            else if(x>n){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return (int) (ans % mod);
    }
};