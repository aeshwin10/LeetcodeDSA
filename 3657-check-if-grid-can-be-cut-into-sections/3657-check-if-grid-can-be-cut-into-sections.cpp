class Solution {
public:
    bool cutPossible(int n, vector<pair<int,int>>& arr){
        int cuts = 0;
        sort(arr.begin(), arr.end());
        int maxEnd = arr[0].second;
        for(auto& interval : arr){
            int start = interval.first, end = interval.second;
            if(maxEnd <= start){
                cuts++;
            }
            maxEnd = max(maxEnd, end);
        }
        return cuts>=2;

    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> xAxis, yAxis;
        for(auto &i : rectangles){
            xAxis.push_back({i[0], i[2]});
            yAxis.push_back({i[1], i[3]});
        }

        if(cutPossible(n, xAxis)) return true;
        if(cutPossible(n, yAxis)) return true;
        return false;
    }
};