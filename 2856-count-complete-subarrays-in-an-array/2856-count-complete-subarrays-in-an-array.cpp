class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int> tempMp;
        for(auto &i : nums){
            tempMp[i]++;
        }
        int uniqueEle = tempMp.size();

        int left = 0;
        int ans = 0;
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            while(left<=i && (mp.size()==uniqueEle)){
                ans += ((n-i));
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }
        }
        return ans;
    }
};