class Solution {
public:
    bool check(long long mid, vector<int>& candies, long long k){
        long long piles = 0;
        for(auto &i : candies){
            piles+= i/mid;
        }
        return piles >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long summ = accumulate(candies.begin(), candies.end(), 0ll);
        if(summ<k){
            return 0;
        }
        
        long long low = 1ll;
        long long high = *max_element(candies.begin(), candies.end());
        long long ans = 1ll;

        while(low<=high){
            long long mid = (low+high)/2;

            if(check(mid, candies, k)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return (int)ans;
    }
};