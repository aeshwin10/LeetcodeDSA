class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];
        vector<vector<int>> ans;
        int n = intervals.size();

        int i=0;
        while(i<n && intervals[i][1]<start){
            ans.push_back(intervals[i]);
            i++;
        }
        int mini = start;
        int maxi = end; 
        while(i<n && intervals[i][0]<=end){
            mini = min(mini,intervals[i][0]);
            maxi = max(maxi, intervals[i][1]);
            i++;
        }
        vector<int> temp;
        temp.push_back(mini);
        temp.push_back(maxi);
        ans.push_back(temp);

        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};