class Solution {
public:

    bool check(int idx, int val){
        return val*2 > idx;
    }

    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int> mp;
        for(auto& i : nums){
            mp[i]++;
        }

        int curMaxFreq = 0;
        int domEle;
        for(auto [key, val] : mp){
            if(val>curMaxFreq){
                domEle = key;
                curMaxFreq = val;
            }
        }

        vector<int> domCount(n, 0);
        if(nums[0]==domEle) domCount[0] = 1;
        for(int i=1; i<n; i++){
            if(nums[i]==domEle){
                domCount[i] = domCount[i-1] + 1;
            }
            else{
                domCount[i] = domCount[i-1];
            }
        }

        for(int i=0; i<n-1; i++){
            int left = i+1;
            int right = n-(i+1);
            int curDomVal = domCount[i];
            int curDomValRight = domCount[n-1] - domCount[i];
            if(check(left, curDomVal) && check(right, curDomValRight)){
                return i;
            }
        }
        return -1;
    }
};