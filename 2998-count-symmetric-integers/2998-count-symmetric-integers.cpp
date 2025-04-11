class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low; i<=high; i++){
            string s = to_string(i);
            if(s.size() & 1) continue;
            int preSum = 0, sufSum = 0;
            int n = s.size();
            for(int i=0; i<n/2; i++){
                preSum+=s[i]-'0';
                sufSum+=s[n-(i+1)] - '0';
            }
            if(preSum==sufSum) ans++;
        }
        return ans;
    }
};