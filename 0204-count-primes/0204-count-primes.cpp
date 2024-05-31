class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> primes(n+1, 1);
        for(int i = 2; i<n; i++){
            if(!primes[i]){
                continue;
            }
            count++;
            for(long j = (long)i*i; j<n; j+=i){
                primes[j]=0;
            }
        }
        return count;
    }
};