class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> right;
        int pivotCount = 0;

        for(auto num : nums){
            if(num==pivot) pivotCount++;
            if(num<pivot) left.push_back(num);
            if(num>pivot) right.push_back(num);
        }
        vector<int> ans = left;
        while(pivotCount--) ans.push_back(pivot);
        for(auto num : right) ans.push_back(num);

        return ans;
    }
};