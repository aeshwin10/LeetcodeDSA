class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            for(int j=0; j<nums[i].size(); j++){
                arr.push_back({nums[i][j], i});
            }
        }
        sort(arr.begin(), arr.end());
        map<int,int> mp;

        int i=0;
        int j=0;
        int mini = INT_MAX;
        int idxVal1 = -1;
        int idxVal2 = -1;

        while(i<arr.size() && j<arr.size()){
            mp[arr[j].second]++;
            
            while(mp.size()>=n && i<=j){
                if(abs((arr[j].first)-(arr[i].first)) < mini){
                    mini = abs((arr[j].first)-(arr[i].first));
                    idxVal1 = arr[j].first;
                    idxVal2 = arr[i].first;
                }
                mp[arr[i].second]--;
                if(mp[arr[i].second]==0){
                    mp.erase(arr[i].second);
                }
                i++;
            }
            j++;
        }
        vector<int> ans(2);
        ans[0] = idxVal2;
        ans[1] = idxVal1;
        return ans;
    }
};