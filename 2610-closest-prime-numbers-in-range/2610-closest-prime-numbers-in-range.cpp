class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> arr(right+1, 1);
        vector<int> primes;
        function<void()> getAllPrimes = [&](){
            for(int i=2; i<=right; i++){
                if(arr[i]){
                    if(i>=left) primes.push_back(i);
                    for(long long j=(long long)i*i; j<right+1; j+=i){
                        arr[j] = 0;
                    }
                }
            }
        };
        getAllPrimes();
        if(primes.size()<=1) return {-1, -1};
        int idx1 = 0;
        int idx2 = 1;
        int diff = primes[1]-primes[0];
        for(int i=2; i<primes.size(); i++){
            int currDiff = primes[i]-primes[i-1];
            if(currDiff<diff){
                idx1 = i-1;
                idx2 = i;
                diff = currDiff;
            }
        }
        return {primes[idx1], primes[idx2]};
    }
};