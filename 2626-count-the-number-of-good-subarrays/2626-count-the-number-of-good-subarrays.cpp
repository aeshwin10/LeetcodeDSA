class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,int> mp;
        mp[nums[0]]++;
        int i=0;
        long long tempPairs = 0;

        for(int j=1; j<n; j++){
            int tempVal = mp[nums[j]];
            tempPairs -= (1ll* tempVal * (tempVal-1) / 2);
            mp[nums[j]]++;
            tempVal = mp[nums[j]];
            tempPairs += (1ll* tempVal * (tempVal-1) / 2);

            while(tempPairs>=k && i<=j){
                ans += (n-j);

                int tempVal1 = mp[nums[i]];
                tempPairs-= (1ll* tempVal1 * (tempVal1-1) / 2);
                mp[nums[i]]--;
                tempVal1 = mp[nums[i]];
                tempPairs+= (1ll* tempVal1 * (tempVal1-1) / 2);
                i++;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
            }
        }
        return ans;
    }
};