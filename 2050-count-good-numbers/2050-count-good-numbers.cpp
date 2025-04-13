class Solution {
const int mod = 1e9+7;
public:
    long long pow(long long a, long long b){
        long long result = 1ll;
        while(b>0){
            if(b&1) result = (result * a) % mod;
            a = ((a * a) % mod);
            b /=2;
        }
        return result;
    }
    
    int countGoodNumbers(long long n) {
        long long ans1 = 1ll;
        long long ans2 = 1ll;
        long long power5 = pow(5, (n+1)/2);
        long long power4 = pow(4, n/2);
        return (((power5 % mod) * (power4 % mod)) % mod);
    }

};