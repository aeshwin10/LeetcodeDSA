class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> arr(53, 0);
        for(auto &i : ranges){
            arr[i[0]]++;
            arr[i[1]+1]--;
        }
        int count = 0;
        for(int i=1; i<=52; i++){
            count += arr[i];
            if(count==0 && i>=left && i<=right){
                return false;
            }
        }
        return true;

    }
};