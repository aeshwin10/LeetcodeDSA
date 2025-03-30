class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        
        vector<int> firstOcc(26, INT_MAX);
        vector<int> lastOcc(26, -1);

        for(int i=0; i<n; i++){
            char curChar = s[i] - 'a';
            firstOcc[curChar] = min(firstOcc[curChar], i);
            lastOcc[curChar] = max(lastOcc[curChar], i);
        }
        vector<pair<int,int>> arr;
        for(int i=0; i<26; i++){
            if(firstOcc[i]!=INT_MAX){
                arr.emplace_back(firstOcc[i], lastOcc[i]);
            }
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int globMin = arr[0].first;
        int globMax = arr[0].second;
        for(int i=1; i<arr.size(); i++){
            int curMin = arr[i].first;
            int curMax = arr[i].second;
            if(curMin==globMax+1){
                ans.push_back(globMax-globMin+1);
                globMin = curMin;
                globMax = curMax;
            }
            else{
                globMax = max(globMax, curMax);
            }
        }
        ans.push_back(globMax - globMin + 1);
        return ans;
    }
};