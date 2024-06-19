class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int n = intervals.size();

        int end = intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0]<end){
                end = min(end,intervals[i][1]);
                count++;
            }
            else{
                end = intervals[i][1];
            }
        }
        return count;
    }
};