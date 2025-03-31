class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int> possWeights;
        if(k==1 || k==n){
            return 0ll;
        }
        //long long ans = (long long) weights[0] + weights[n-1];
        for(int i=0; i<n-1; i++){
            possWeights.push_back((long long)weights[i]+weights[i+1]);
        }
        sort(possWeights.begin(), possWeights.end());

        long long minPoss = 0ll;
        long long maxPoss = 0ll;
        int m = possWeights.size();
        for(int i=0; i<min(m, k-1); i++){
            minPoss+=possWeights[i];
            maxPoss+=possWeights[m-(i+1)];
        }
        return (long long)maxPoss - minPoss;

    }
};