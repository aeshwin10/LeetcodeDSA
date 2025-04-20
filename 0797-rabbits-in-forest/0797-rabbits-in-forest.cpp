class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        int n = answers.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[answers[i]]++;
        }
        
        for(auto [key, val] : mp){
            int denom = key+1;
            ans += ((key+1)*((val + key)/denom));
        }
        return ans;
    }
};